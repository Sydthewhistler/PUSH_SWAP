/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:56:51 by scavalli          #+#    #+#             */
/*   Updated: 2025/03/27 15:02:03 by scavalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*nomad_node;

	if (!*src)
		return ;
	nomad_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	nomad_node->previous = NULL;
	if (!*dst)
	{
		*dst = nomad_node;
		nomad_node->next = NULL;
	}
	else
	{
		nomad_node->next = *dst;
		(*dst)->previous = nomad_node;
		*dst = nomad_node;
	}
}
