/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:49:26 by nvideira          #+#    #+#             */
/*   Updated: 2022/05/21 07:57:15 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putinbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
			count++;
		}
		if (n >= 10)
		{
			count += ft_putinbr_fd((n / 10), fd);
			count += ft_putinbr_fd((n % 10), fd);
		}
		else
			count += ft_putchari_fd((n + '0'), fd);
	}
	return (count);
}

int	ft_putunsnbr_fd(unsigned int n, int fd)
{
	unsigned int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putunsnbr_fd((n / 10), fd);
		count += ft_putunsnbr_fd((n % 10), fd);
	}
	else
		count += ft_putchari_fd((n + '0'), fd);
	return (count);
}
