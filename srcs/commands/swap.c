/* swap.c - swap_top (silent) and sa (with print) */

#include "../../inc/header.h"

void	swap_top(t_stack **stack)
{
	t_stack	*second;

	second = (*stack)->next;
	(*stack)->next = second->next;
	second->next->previous = *stack;
	(*stack)->previous = second;
	second->previous = NULL;
	second->next = *stack;
	*stack = (*stack)->previous;
}

void	sa(t_stack **stack)
{
	swap_top(stack);
	ft_printf("sa\n");
}
