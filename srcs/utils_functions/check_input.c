/* check_input.c - argument validation (integers, range, duplicates) */

#include "../../inc/header.h"

/* Returns 0 if str represents a valid int, -1 otherwise. */
static int	str_is_int(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	for (; *str >= '0' && *str <= '9'; str++)
	{
		if (result > (LONG_MAX - (*str - '0')) / 10)
			return (-1);
		result = result * 10 + (*str - '0');
	}
	result *= sign;
	if (result < INT_MIN || result > INT_MAX)
		return (-1);
	return (0);
}

static int	has_duplicate(char **av, int ac)
{
	int	start;
	int	j;

	start = (ac == 2) ? 0 : 1;
	for (int i = start; av[i]; i++)
	{
		for (j = 1; av[i + j]; j++)
		{
			if (str_equal(av[i], av[i + j]))
				return (-1);
		}
	}
	return (0);
}

int	validate_args(char **av, int ac)
{
	int	start;

	start = (ac == 2) ? 0 : 1;
	for (int i = start; av[i]; i++)
	{
		for (int j = 0; av[i][j]; j++)
		{
			if (av[i][j] != '-' && !(av[i][j] >= '0' && av[i][j] <= '9'))
				return (-1);
		}
		if (str_is_int(av[i]) == -1)
			return (-1);
	}
	return (has_duplicate(av, ac));
}
