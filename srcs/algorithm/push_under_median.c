/* push_under_median.c - compute the median value of a stack */

#include "../../inc/header.h"

static void	fill_array(int *arr, t_stack *stack, int size)
{
	for (int i = 0; i < size; i++, stack = stack->next)
		arr[i] = stack->content;
}

static void	sort_array(int *arr, int size)
{
	int	tmp;

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
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
	t_stack	*tmp;
	int		*arr;
	int		size;
	int		median;

	size = 0;
	for (tmp = stack; tmp; tmp = tmp->next)
		size++;
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

bool	has_value_below(t_stack *stack, int threshold)
{
	for (; stack; stack = stack->next)
	{
		if (stack->content < threshold)
			return (true);
	}
	return (false);
}
