/* sort_turk.c - Turk algorithm: quartile pre-sort then greedy merge */

#include "../../inc/header.h"

void	sort_turk(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	push_by_quartiles(stack_a, stack_b);
	size = (int)stack_size(*stack_a);
	while (size-- > 3 && !is_sorted(*stack_a))
		pb(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		prepare_b_nodes(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	stack_index_nodes(*stack_a);
	rotate_min_to_top(stack_a);
}
