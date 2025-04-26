/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:02:27 by scavalli          #+#    #+#             */
/*   Updated: 2025/03/27 12:51:17 by scavalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	sa(t_stack **stack)
{
	t_stack	*second_node;

	second_node = (*stack)->next;
	(*stack)->next = second_node->next;
	second_node->next->previous = (*stack);
	(*stack)->previous = second_node;
	second_node->previous = NULL;
	second_node->next = *stack;
	*stack = (*stack)->previous;
	ft_printf("sa\n");
}
