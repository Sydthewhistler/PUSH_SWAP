/* initialise_stack_a.c - populate stack A from argument list */

#include "../../inc/header.h"

void	stack_a_init(char **av, t_stack **stack_a)
{
	for (int i = 0; av[i]; i++)
		stack_push_back(stack_a, ft_atoi(av[i]));
}
