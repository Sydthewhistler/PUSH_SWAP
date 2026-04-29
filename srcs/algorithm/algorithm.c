/* algorithm.c - top-level sort dispatcher */

#include "../../inc/header.h"

bool	is_sorted(t_stack *lst)
{
	if (!lst)
		return (true);
	for (; lst->next; lst = lst->next)
	{
		if (lst->next->content < lst->content)
			return (false);
	}
	return (true);
}

int	algorithm(char **av, int ac)
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	unsigned int	size;

	stack_a = NULL;
	stack_b = NULL;
	stack_a_init(ac > 2 ? av + 1 : av, &stack_a);
	if (!is_sorted(stack_a))
	{
		size = stack_size(stack_a);
		if (size == 2)
			ft_printf("sa\n");
		else if (size == 3)
			sort_three(&stack_a);
		else
			sort_turk(&stack_a, &stack_b);
	}
	stack_free(&stack_a);
	return (0);
}
