/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_printf.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:48:20 by scavalli          #+#    #+#             */
/*   Updated: 2025/03/13 13:12:17 by scavalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_PRINTF_H
# define HEADER_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_put_unsigned_nbr(unsigned int n);
void	ft_putnbr_lowercase_hex(unsigned int n);
void	ft_putnbr_uppercase_hex(unsigned int n);
void	ft_putptr_hex(unsigned long n);
void	ft_putnbr(int n);
int		ft_printf(const char *format, ...);

#endif