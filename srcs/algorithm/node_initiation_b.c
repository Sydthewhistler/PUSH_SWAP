/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_initiation_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:44:17 by scavalli          #+#    #+#             */
/*   Updated: 2025/03/30 18:10:05 by scavalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

static void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	current_biggest_content;
	while (b)
	{
		target_node = NULL;
		current_biggest_content = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->content > b->content 
				&& current_a->content < current_biggest_content)
			{
				current_biggest_content = current_a->content;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (current_biggest_content == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	node_initiation_b(t_stack *stack_a, t_stack *stack_b)
{
	define_index(stack_a);
	define_index(stack_b);
	set_target_b(stack_a, stack_b); //prblm
}

t_stack	*find_min(t_stack *stack_a)
{
	int		min;
	t_stack	*min_node;

	min = stack_a->content;
	min_node = stack_a;
	while (stack_a)
	{
		if (stack_a->content < min)
		{
			min = stack_a->content;
			min_node = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (min_node);
}
