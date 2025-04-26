/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:38:51 by scavalli          #+#    #+#             */
/*   Updated: 2025/03/25 16:43:34 by scavalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_lowercase_hex(unsigned int n)
{
	if (n >= 16)
		ft_putnbr_lowercase_hex(n / 16);
	write(1, &"0123456789abcdef"[n % 16], 1);
}

void	ft_putnbr_uppercase_hex(unsigned int n)
{
	if (n >= 16)
		ft_putnbr_uppercase_hex(n / 16);
	write(1, &"0123456789ABCDEF"[n % 16], 1);
}
