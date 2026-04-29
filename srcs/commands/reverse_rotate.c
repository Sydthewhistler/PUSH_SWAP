/* reverse_rotate.c - rra, rrb, rrr: shift stack downward (bottom → top) */

#include "../../inc/header.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;

	last = find_last(*stack);
	last->previous->next = NULL;
	last->next = *stack;
	last->previous = NULL;
	*stack = last;
	last->next->previous = last;
}

void	rra(t_stack **stack)
{
	reverse_rotate(stack);
	ft_printf("rra\n");
}

void	rrb(t_stack **stack)
{
	reverse_rotate(stack);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
