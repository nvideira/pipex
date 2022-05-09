/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:27:30 by nvideira          #+#    #+#             */
/*   Updated: 2021/12/13 22:02:15 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

size_t	next_arg(char ch, int *c, va_list args)
{
	if (ch == 'c')
		*c += ft_putchar_fd(va_arg(args, int), 1);
	if (ch == 's')
		*c += ft_putstr_fd(va_arg(args, char *), 1);
	if (ch == 'p')
	{
		*c += ft_putstr_fd("0x", 1);
		*c += dec_hexa(va_arg(args, unsigned long long), 1, "0123456789abcdef");
	}
	if (ch == 'd' || ch == 'i')
		*c += ft_putnbr_fd(va_arg(args, int), 1);
	if (ch == 'u')
		*c += ft_putunsnbr_fd(va_arg(args, unsigned int), 1);
	if (ch == 'x')
		*c += dec_hexa(va_arg(args, unsigned int), 1, "0123456789abcdef");
	if (ch == 'X')
		*c += dec_hexa(va_arg(args, unsigned int), 1, "0123456789ABCDEF");
	if (ch == '%')
		*c += ft_putchar_fd('%', 1);
	return (*c);
}
