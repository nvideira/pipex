/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:46:41 by nvideira          #+#    #+#             */
/*   Updated: 2021/12/13 22:27:22 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	do_thing(size_t index, char *string, int char_print, va_list args)
{
	while (string[++index])
	{
		if (string[index] != '%')
		{
			ft_putchar_fd(string[index], 1);
			char_print++;
		}
		else
		{
			if (check_type(string[index + 1]))
			{
				next_arg(string[index + 1], &char_print, args);
				index++;
			}
		}
	}
	return (char_print);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		char_print;
	size_t	index;
	char	*string;

	index = -1;
	char_print = 0;
	string = (char *) s;
	va_start(args, s);
	char_print = do_thing(index, string, char_print, args);
	va_end(args);
	return (char_print);
}
