/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:53:31 by scavalli          #+#    #+#             */
/*   Updated: 2025/05/08 12:07:11 by scavalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	sort_turk(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;

	transfer_by_quartiles(stack_a, stack_b);
	len_a = stack_size(*stack_a);
	while (len_a-- > 3 && !check_if_sorted(*stack_a))
		pb(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		node_initiation_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	define_index(*stack_a);
	put_min_top(stack_a);
}
