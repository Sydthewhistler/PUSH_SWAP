/* sort_3.c - hard-coded optimal sort for 3 elements + find_max helper */

#include "../../inc/header.h"

t_stack	*find_max(t_stack *stack)
{
	t_stack	*max_node;
	int		max;

	if (!stack)
		return (NULL);
	max_node = stack;
	max = stack->content;
	for (; stack->next; stack = stack->next)
	{
		if (stack->next->content > max)
		{
			max_node = stack->next;
			max = max_node->content;
		}
	}
	return (max_node);
}

void	sort_three(t_stack **stack)
{
	t_stack	*max_node;

	max_node = find_max(*stack);
	if (max_node == *stack)
		ra(stack);
	else if (max_node == (*stack)->next)
		rra(stack);
	if ((*stack)->content > (*stack)->next->content)
		sa(stack);
}
