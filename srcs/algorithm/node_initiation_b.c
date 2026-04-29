/* node_initiation_b.c - assign indices, targets and costs to B nodes */

#include "../../inc/header.h"

void	stack_index_nodes(t_stack *lst)
{
	int	median;
	int	i;

	i = 0;
	median = (int)stack_size(lst) / 2;
	for (; lst; lst = lst->next, i++)
	{
		lst->index = i;
		lst->position_from_median = (i < median);
	}
}

static void	assign_b_targets(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_content;

	while (b)
	{
		target_node = NULL;
		best_content = LONG_MAX;
		for (current_a = a; current_a; current_a = current_a->next)
		{
			if (current_a->content > b->content
				&& current_a->content < best_content)
			{
				best_content = current_a->content;
				target_node = current_a;
			}
		}
		b->target = (best_content == LONG_MAX) ? find_min(a) : target_node;
		b = b->next;
	}
}

void	prepare_b_nodes(t_stack *stack_a, t_stack *stack_b)
{
	stack_index_nodes(stack_a);
	stack_index_nodes(stack_b);
	assign_b_targets(stack_a, stack_b);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min_node;
	int		min;

	min_node = stack;
	min = stack->content;
	for (; stack; stack = stack->next)
	{
		if (stack->content < min)
		{
			min = stack->content;
			min_node = stack;
		}
	}
	return (min_node);
}
