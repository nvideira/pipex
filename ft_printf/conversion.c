/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:45:20 by nvideira          #+#    #+#             */
/*   Updated: 2022/05/21 07:53:30 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int	dec_hexa(unsigned long n, int fd, char *base)
{
	int				count;
	unsigned long	unsnum;

	unsnum = n;
	count = 0;
	if (unsnum > 15)
	{
		count += dec_hexa((unsnum / 16), fd, base);
		count += ft_putchari_fd(base[unsnum % 16], fd);
	}
	else
		count += ft_putchari_fd(base[unsnum], fd);
	return (count);
}
