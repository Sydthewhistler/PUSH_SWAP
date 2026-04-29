/* swap.c - sa: swap the two top elements of a stack */

#include "../../inc/header.h"

void	sa(t_stack **stack)
{
	t_stack	*second;

	second = (*stack)->next;
	(*stack)->next = second->next;
	second->next->previous = *stack;
	(*stack)->previous = second;
	second->previous = NULL;
	second->next = *stack;
	*stack = (*stack)->previous;
	ft_printf("sa\n");
}
