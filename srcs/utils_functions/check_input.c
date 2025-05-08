/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:51:12 by scavalli          #+#    #+#             */
/*   Updated: 2025/05/08 16:31:47 by scavalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

static int	ft_nb_is_int(const char *str)
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
	while (*str >= '0' && *str <= '9')
	{
		if (result > (LONG_MAX - (*str - '0')) / 10)
			return (-1);
		result = result * 10 + (*str - '0');
		str++;
	}
	result *= sign;
	if (result < INT_MIN || result > INT_MAX)
		return (-1);
	return (0);
}

static int	check_duplicate(char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	if (ac == 2)
		i = 0;
	j = 0;
	while (av[i])
	{
		j = 1;
		while (av[i + j])
		{
			if (ft_strcmp(av[i], av[i + j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_av(char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	if (ac == 2)
		i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] != '-' && !('0' <= av[i][j] && av[i][j] <= '9'))
				return (-1);
			j++;
		}
		if (ft_nb_is_int(av[i]) == -1)
			return (-1);
		i++;
	}
	if (check_duplicate(av, ac) == -1)
		return (-1);
	return (0);
}
