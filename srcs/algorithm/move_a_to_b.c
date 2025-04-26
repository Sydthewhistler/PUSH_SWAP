/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:36:42 by scavalli          #+#    #+#             */
/*   Updated: 2025/03/30 18:17:58 by scavalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

static t_stack	*find_cheapest(t_stack *stack_a)
{
	while (stack_a)
	{
		if (stack_a->cheapest)
			return (stack_a);
		stack_a = stack_a->next;
	}
	return (NULL);
}

static void	rotate_both(t_stack **stack_a, t_stack **stack_b,
		t_stack *cheapest_node)
{
	while (*stack_b != cheapest_node->target && *stack_a != cheapest_node)
		rr(stack_a, stack_b);
	define_index(*stack_a);
	define_index(*stack_b);
}

static void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b,
		t_stack *cheapest_node)
{
	while (*stack_b != cheapest_node->target && *stack_a != cheapest_node)
		rrr(stack_a, stack_b);
	define_index(*stack_a);
	define_index(*stack_b);
}

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

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;

	cheapest_node = find_cheapest(*stack_a);
	if ((*stack_a)->position_from_median && (*stack_a)->target->position_from_median)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (!((*stack_a)->position_from_median)
		&& !((*stack_a)->target->position_from_median))
		reverse_rotate_both(stack_a, stack_b, cheapest_node);
	prep_for_push(stack_a, cheapest_node, STACK_A);
	prep_for_push(stack_b, cheapest_node->target, STACK_B);
	pb(stack_a, stack_b);
}
