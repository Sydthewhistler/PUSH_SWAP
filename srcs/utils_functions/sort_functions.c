/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:42:30 by scavalli          #+#    #+#             */
/*   Updated: 2025/05/08 12:07:20 by scavalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	prep_for_push(t_stack **stack, t_stack *top_node, bool which_stack)
{
	while (*stack != top_node)
	{
		if (which_stack == STACK_A)
		{
			if (top_node->position_from_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (which_stack == STACK_B)
		{
			if (top_node->position_from_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	put_min_top(t_stack **top_node)
{
	t_stack	*min_node;

	min_node = find_min(*top_node);
	while (*top_node != min_node)
	{
		if (min_node->position_from_median)
			ra(top_node);
		else
			rra(top_node);
	}
}

t_stack	*find_last(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
