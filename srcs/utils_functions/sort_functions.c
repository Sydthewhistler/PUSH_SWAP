/* sort_functions.c - rotation helpers and find_last */

#include "../../inc/header.h"

t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	for (; stack->next; stack = stack->next)
		;
	return (stack);
}

/* Rotate stack until node is on top, choosing the cheaper direction. */
void	bring_node_to_top(t_stack **stack, t_stack *node, bool which_stack)
{
	while (*stack != node)
	{
		if (!which_stack)
		{
			node->position_from_median ? ra(stack) : rra(stack);
		}
		else
		{
			node->position_from_median ? rb(stack) : rrb(stack);
		}
	}
}

void	rotate_min_to_top(t_stack **stack)
{
	t_stack	*min_node;

	min_node = find_min(*stack);
	while (*stack != min_node)
	{
		min_node->position_from_median ? ra(stack) : rra(stack);
	}
}
