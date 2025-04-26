/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:19:58 by scavalli          #+#    #+#             */
/*   Updated: 2025/04/02 21:55:53 by scavalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

bool	check_if_sorted(t_stack *lst)
{
	if (!lst)
		return (1);
	while (lst && lst->next)
	{
		if (lst->next->content < lst->content)
			return (false);
		lst = lst->next;
	}
	return (true);
}

int	algorithm(char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	initialise_stack_a(av + 1, &stack_a);
	if (!check_if_sorted(stack_a))
	{
		if (stack_size(stack_a) == 2)
		{
			ft_printf("sa\n");
			ft_lstclear_stack(&stack_a);
			return (0);
		}
		else if (stack_size(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_turk(&stack_a, &stack_b);
	}
	ft_lstclear_stack(&stack_a);
	return (0);
}
