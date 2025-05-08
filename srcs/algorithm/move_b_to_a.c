/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:32:26 by scavalli          #+#    #+#             */
/*   Updated: 2025/05/08 12:11:15 by scavalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

static int	calculate_cost(t_stack *a, t_stack *b, t_stack *node_a,
		t_stack *node_b)
{
	int	cost_a;
	int	cost_b;
	int	total_cost;

	if (node_a->position_from_median)
		cost_a = node_a->index;
	else
		cost_a = stack_size(a) - node_a->index;
	if (node_b->position_from_median)
		cost_b = node_b->index;
	else
		cost_b = stack_size(b) - node_b->index;
	if ((node_a->position_from_median && node_b->position_from_median)
		|| (!node_a->position_from_median && !node_b->position_from_median))
	{
		total_cost = cost_a;
		if (cost_b > cost_a)
			total_cost = cost_b;
	}
	else
		total_cost = cost_a + cost_b;
	return (total_cost);
}

static void	apply_rotations(t_stack **a, t_stack **b, t_stack *node_a,
		t_stack *node_b)
{
	if (node_a->position_from_median && node_b->position_from_median)
	{
		while (*a != node_a && *b != node_b)
			rr(a, b);
		while (*a != node_a)
			ra(a);
		while (*b != node_b)
			rb(b);
	}
	else if (!node_a->position_from_median && !node_b->position_from_median)
	{
		while (*a != node_a && *b != node_b)
			rrr(a, b);
		while (*a != node_a)
			rra(a);
		while (*b != node_b)
			rrb(b);
	}
	else
	{
		prep_for_push(a, node_a, STACK_A);
		prep_for_push(b, node_b, STACK_B);
	}
}

static t_stack	*find_best_node_b(t_stack *a, t_stack *b,
		t_stack **best_target_a)
{
	t_stack	*best_b;
	t_stack	*current;
	int		min_cost;
	int		current_cost;

	best_b = b;
	min_cost = INT_MAX;
	current = b;
	while (current)
	{
		current_cost = calculate_cost(a, b, current->target, current);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			best_b = current;
			*best_target_a = current->target;
		}
		current = current->next;
	}
	return (best_b);
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*best_b;
	t_stack	*best_target_a;

	best_target_a = NULL;
	best_b = find_best_node_b(*a, *b, &best_target_a);
	apply_rotations(a, b, best_target_a, best_b);
	pa(a, b);
}
