/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:33:11 by nvideira          #+#    #+#             */
/*   Updated: 2022/05/21 07:55:48 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstri_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (ft_strlen(s));
}
