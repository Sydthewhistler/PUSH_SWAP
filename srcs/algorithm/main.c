/* main.c - entry point, argument parsing */

#include "../../inc/header.h"

static void	free_split(char **tab)
{
	for (int i = 0; tab[i]; i++)
		free(tab[i]);
	free(tab);
}

int	main(int ac, char **av)
{
	bool	split_mode;

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
	algorithm(av, ac);
	if (split_mode)
		free_split(av);
	return (0);
}
