/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:35:01 by nvideira          #+#    #+#             */
/*   Updated: 2022/05/21 12:52:59 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char )c && *s != '\0')
		s++;
	if (*s == (char )c)
		return ((char *)s);
	else
		return (NULL);
}
