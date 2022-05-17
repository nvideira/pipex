/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:00:32 by nvideira          #+#    #+#             */
/*   Updated: 2021/10/31 20:33:54 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ini;
	int			i;

	ini = s;
	i = ft_strlen(s);
	s += i;
	while (s != ini && *s != (unsigned char )c)
		s--;
	if (*s == (unsigned char )c)
		return ((char *)s);
	return (0);
}
