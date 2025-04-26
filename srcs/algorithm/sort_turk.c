/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:53:31 by scavalli          #+#    #+#             */
/*   Updated: 2025/03/30 18:16:47 by scavalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	sort_turk(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;

	len_a = stack_size(*stack_a);
	if (len_a-- > 3 && !check_if_sorted(*stack_a))
		pb(stack_a, stack_b);
	if (len_a > 3 && !check_if_sorted(*stack_a))
		pb(stack_a, stack_b);
	while (len_a-- > 4 && !check_if_sorted(*stack_a))
	{
		node_initiation_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		node_initiation_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	define_index(*stack_a);
	put_min_top(stack_a);
}
