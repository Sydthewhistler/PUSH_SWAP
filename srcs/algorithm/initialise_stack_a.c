/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_stack_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 17:04:10 by scavalli          #+#    #+#             */
/*   Updated: 2025/03/27 12:22:38 by scavalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	initialise_stack_a(char **av, t_stack **stack_a)
{
	unsigned int	i;

	i = 0;
	while (av[i])
	{
		ft_lst_add_new_last(stack_a, ft_atoi(av[i]));
		i++;
	}
	return ;
}
