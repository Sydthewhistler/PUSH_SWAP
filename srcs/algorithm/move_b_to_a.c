/* move_b_to_a.c - find cheapest B node and rotate both stacks to push it */

#include "../../inc/header.h"

static int	compute_move_cost(t_stack *a, t_stack *b,
				t_stack *node_a, t_stack *node_b)
{
	int	cost_a;
	int	cost_b;

	cost_a = node_a->position_from_median
		? (int)node_a->index
		: (int)(stack_size(a) - node_a->index);
	cost_b = node_b->position_from_median
		? (int)node_b->index
		: (int)(stack_size(b) - node_b->index);
	if (node_a->position_from_median == node_b->position_from_median)
		return (cost_a > cost_b ? cost_a : cost_b);
	return (cost_a + cost_b);
}

static void	apply_rotations(t_stack **a, t_stack **b,
				t_stack *node_a, t_stack *node_b)
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
		bring_node_to_top(a, node_a, STACK_A);
		bring_node_to_top(b, node_b, STACK_B);
	}
}

static t_stack	*find_cheapest_b(t_stack *a, t_stack *b,
					t_stack **best_target_a)
{
	t_stack	*best_b;
	t_stack	*current;
	int		min_cost;
	int		cost;

	best_b = b;
	min_cost = INT_MAX;
	for (current = b; current; current = current->next)
	{
		cost = compute_move_cost(a, b, current->target, current);
		if (cost < min_cost)
		{
			min_cost = cost;
			best_b = current;
			*best_target_a = current->target;
		}
	}
	return (best_b);
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*best_b;
	t_stack	*best_target_a;

	best_target_a = NULL;
	best_b = find_cheapest_b(*a, *b, &best_target_a);
	apply_rotations(a, b, best_target_a, best_b);
	pa(a, b);
}
