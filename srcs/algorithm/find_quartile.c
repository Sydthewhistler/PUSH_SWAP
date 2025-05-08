/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_quartile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:17:15 by scavalli          #+#    #+#             */
/*   Updated: 2025/05/08 16:30:04 by scavalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	fill_stack(t_stack **filtered_list, t_stack *new_node)
{
	t_stack	*temp;

	if (!*filtered_list)
		*filtered_list = new_node;
	else
	{
		temp = *filtered_list;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}

t_stack	*ft_create_filtered_list(t_stack *lst, int median, int is_upper)
{
	t_stack	*filtered_list;
	t_stack	*current;
	t_stack	*new_node;
	t_stack	*temp;

	filtered_list = NULL;
	temp = NULL;
	current = lst;
	while (current)
	{
		if ((is_upper && current->content > median) || (!is_upper
				&& current->content < median))
		{
			new_node = (t_stack *)malloc(sizeof(t_stack));
			if (free_lst(filtered_list, temp, new_node) == -1)
				return (NULL);
			new_node->content = current->content;
			new_node->next = NULL;
			fill_stack(&filtered_list, new_node);
		}
		current = current->next;
	}
	return (filtered_list);
}

int	find_quartile(t_stack *lst, int median, int is_upper)
{
	t_stack	*filtered_list;
	t_stack	*current;
	t_stack	*temp;
	int		quartile;

	filtered_list = ft_create_filtered_list(lst, median, is_upper);
	if (!filtered_list)
		return (0);
	quartile = find_median(filtered_list);
	current = filtered_list;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	return (quartile);
}

void	transfer_lower_quartiles(t_stack **a, t_stack **b, int q1, int median)
{
	while (stack_size(*a) > 3 && number_under_median(*a, q1))
	{
		if ((*a)->content < q1)
			pb(a, b);
		else
			ra(a);
	}
	while (stack_size(*a) > 3 && number_under_median(*a, median))
	{
		if ((*a)->content >= q1 && (*a)->content < median)
			pb(a, b);
		else
			ra(a);
	}
}

void	transfer_by_quartiles(t_stack **a, t_stack **b)
{
	int	q1;
	int	median;
	int	q3;

	if (stack_size(*a) <= 3)
		return ;
	median = find_median(*a);
	q1 = find_quartile(*a, median, LOWER_QUARTILE);
	q3 = find_quartile(*a, median, UPPER_QUARTILE);
	transfer_lower_quartiles(a, b, q1, median);
	while (stack_size(*a) > 3 && number_under_median(*a, q3))
	{
		if ((*a)->content >= median && (*a)->content < q3)
			pb(a, b);
		else
			ra(a);
	}
	while (stack_size(*a) > 3)
		pb(a, b);
}
