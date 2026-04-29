/* checker/main.c - read push_swap instructions from stdin and verify the result */

#include "../../inc/header.h"

static void	free_split(char **tab)
{
	for (int i = 0; tab[i]; i++)
		free(tab[i]);
	free(tab);
}

/* Read one instruction line from stdin. Returns NULL on EOF. */
static char	*read_line(void)
{
	char	*line;
	char	c;
	int		i;

	line = malloc(8);
	if (!line)
		return (NULL);
	i = 0;
	while (read(STDIN_FILENO, &c, 1) > 0 && c != '\n')
	{
		if (i < 7)
			line[i++] = c;
	}
	line[i] = '\0';
	if (i == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/* Apply one instruction silently. Returns -1 if unknown. */
static int	apply(const char *inst, t_stack **a, t_stack **b)
{
	if (str_equal(inst, "sa"))  { swap_top(a);                           return (0); }
	if (str_equal(inst, "ra"))  { rotate(a);                             return (0); }
	if (str_equal(inst, "rb"))  { rotate(b);                             return (0); }
	if (str_equal(inst, "rr"))  { rotate(a); rotate(b);                  return (0); }
	if (str_equal(inst, "rra")) { reverse_rotate(a);                     return (0); }
	if (str_equal(inst, "rrb")) { reverse_rotate(b);                     return (0); }
	if (str_equal(inst, "rrr")) { reverse_rotate(a); reverse_rotate(b);  return (0); }
	if (str_equal(inst, "pa"))  { push(b, a);                            return (0); }
	if (str_equal(inst, "pb"))  { push(a, b);                            return (0); }
	return (-1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;
	bool	split_mode;
	bool	error;

	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (-1);
	split_mode = (ac == 2);
	if (split_mode)
		av = ft_split(av[1], " ");
	if (validate_args(av, ac) == -1)
	{
		ft_printf("Error\n");
		if (split_mode)
			free_split(av);
		return (-1);
	}
	stack_a = NULL;
	stack_b = NULL;
	stack_a_init(ac > 2 ? av + 1 : av, &stack_a);
	if (split_mode)
		free_split(av);
	error = false;
	while (!error && (line = read_line()) != NULL)
	{
		if (apply(line, &stack_a, &stack_b) == -1)
			error = true;
		free(line);
	}
	if (error)
		ft_printf("Error\n");
	else if (is_sorted(stack_a) && !stack_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	stack_free(&stack_a);
	stack_free(&stack_b);
	return (0);
}
