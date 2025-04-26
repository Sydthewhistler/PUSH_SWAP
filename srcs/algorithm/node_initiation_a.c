/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_initiation_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 09:29:56 by scavalli          #+#    #+#             */
/*   Updated: 2025/03/26 16:23:09 by scavalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	define_index(t_stack *lst)
{
	int	median;
	int	i;

	i = 0;
	median = stack_size(lst) / 2;
	while (lst)
	{
		lst->index = i;
		if (i < median)
			lst->position_from_median = BELOW;
		else
			lst->position_from_median = ABOVE;
		lst = lst->next;
		i++;
	}
}

static void	set_target_a(t_stack *stack_a, t_stack *stack_b)
{
	int		target_value;
	t_stack	*first_node_b;

	first_node_b = stack_b;
	target_value = 2147483647;
	while (stack_a)
	{
		while (stack_b)
		{
			if ((stack_b->content < stack_a->content)
				&& (stack_b->content <= target_value))
			{
				stack_a->target = stack_b;
				target_value = stack_b->content;
			}
			stack_b = stack_b->next;
		}
		stack_b = first_node_b;
		if (!stack_a->target)
			stack_a->target = find_max(stack_b);
		stack_a = stack_a->next;
	}
}

static void	cost_analysis(t_stack *stack_from, t_stack *stack_to)
{
	int	len_stack_from;
	int	len_stack_to;

	len_stack_from = stack_size(stack_from);
	len_stack_to = stack_size(stack_to);
	while (stack_from)
	{
		stack_from->push_cost = stack_from->index;
		if (!(stack_from->position_from_median)) // au dessus médiane
			stack_from->push_cost = len_stack_from - stack_from->index;
		if (stack_from->target->position_from_median) // en dessous médiane
			stack_from->push_cost += stack_from->target->index;
		else
			stack_from->push_cost += len_stack_to - stack_from->target->index;
		stack_from = stack_from->next;
	}
}

static void	set_cheapest(t_stack *stack_from)
{
	int		cheapest_value;
	t_stack	*cheapest_node;

	cheapest_value = 2147483647;
	while (stack_from)
	{
		if (stack_from->push_cost <= cheapest_value)
		{
			cheapest_value = stack_from->push_cost;
			cheapest_node = stack_from;
		}
		stack_from = stack_from->next;
	}
	cheapest_node->cheapest = true;
}

void	node_initiation_a(t_stack *stack_from, t_stack *stack_to)
{
	define_index(stack_from);
	define_index(stack_to);
	set_target_a(stack_from, stack_to);
	cost_analysis(stack_from, stack_to);
	set_cheapest(stack_from);
}
