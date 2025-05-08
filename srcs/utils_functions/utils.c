/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:18:41 by scavalli          #+#    #+#             */
/*   Updated: 2025/05/08 16:30:19 by scavalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int	free_lst(t_stack *filtered_list, t_stack *temp, t_stack *new_node)
{
	if (!new_node)
	{
		while (filtered_list)
		{
			temp = filtered_list;
			filtered_list = filtered_list->next;
			free(temp);
		}
		return (-1);
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}
