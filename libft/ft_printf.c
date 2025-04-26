/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:52:43 by scavalli          #+#    #+#             */
/*   Updated: 2025/03/25 16:42:37 by scavalli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	type_format(char specifier, va_list args)
{
	if (specifier == 'd' || specifier == 'i')
		ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		ft_put_unsigned_nbr(va_arg(args, unsigned int));
	else if (specifier == 's')
		ft_putstr(va_arg(args, char *));
	else if (specifier == '%')
		write(1, "%", 1);
	else if (specifier == 'c')
		ft_putchar(va_arg(args, int));
	else if (specifier == 'p')
	{
		write(1, "0x", 2);
		ft_putptr_hex((unsigned long)va_arg(args, void *));
	}
	else if (specifier == 'x')
		ft_putnbr_lowercase_hex(va_arg(args, unsigned int));
	else if (specifier == 'X')
		ft_putnbr_uppercase_hex(va_arg(args, unsigned int));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			type_format(format[i + 1], args);
			if (format[i + 1] != '%')
				va_arg(args, void *);
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
		}
	}
	va_end(args);
	return (0);
}
