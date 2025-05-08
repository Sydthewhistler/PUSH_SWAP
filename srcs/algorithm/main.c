/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 11:00:03 by scavalli          #+#    #+#             */
/*   Updated: 2025/05/08 16:31:39 by scavalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	main(int ac, char **av)
{
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (-1);
	if (ac == 2)
		av = ft_split(av[1], " ");
	if (check_av(av, ac) == -1)
	{
		ft_printf("Error\n");
		if (ac == 2)
			ft_free_tab(av);
		return (-1);
	}
	algorithm(av, ac);
	if (ac == 2)
		ft_free_tab(av);
	return (0);
}
