/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:27:08 by scavalli          #+#    #+#             */
/*   Updated: 2025/05/08 12:06:11 by scavalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	ft_lst_add_new_last(t_stack **stack, int content)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->content = content;
	node->cheapest = 0;
	if (!(*stack))
	{
		*stack = node;
		node->previous = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->previous = last_node;
	}
}

void	ft_lstclear_stack(t_stack **lst)
{
	t_stack	*copy;

	if (!*lst || !lst)
		return ;
	while (*lst)
	{
		copy = *lst;
		*lst = (*lst)->next;
		free(copy);
	}
}

unsigned int	stack_size(t_stack *stack_a)
{
	int	size;

	if (!stack_a)
		return (0);
	size = 0;
	while (stack_a)
	{
		size++;
		stack_a = stack_a->next;
	}
	return (size);
}
