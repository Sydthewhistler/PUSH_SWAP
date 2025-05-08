/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_under_median.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:06:07 by scavalli          #+#    #+#             */
/*   Updated: 2025/05/08 12:07:06 by scavalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

static void	fill_array(int *arr, t_stack *stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i++] = stack->content;
		stack = stack->next;
	}
}

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

int	find_median(t_stack *stack)
{
	int		size;
	int		median;
	int		*arr;
	t_stack	*tmp;

	size = 0;
	tmp = stack;
	while (tmp && ++size)
		tmp = tmp->next;
	if (size == 0)
		return (0);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	fill_array(arr, stack, size);
	sort_array(arr, size);
	median = arr[size / 2];
	free(arr);
	return (median);
}

bool	number_under_median(t_stack *stack, int median)
{
	while (stack)
	{
		if (stack->content < median)
			return (true);
		stack = stack->next;
	}
	return (false);
}
