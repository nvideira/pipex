/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:45:09 by nvideira          #+#    #+#             */
/*   Updated: 2022/05/25 12:04:40 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strichr(const char *s, int start, int c)
{
	while (s[start] != (char )c && s[start] != '\0')
		start++;
	if (s[start] == (char )c)
		return (start);
	else
		return (-1);
}

char	*ft_substring(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!len || ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s))
	{
		len = ft_strlen(s);
		return (ft_substr(s, start, len));
	}
	sub = malloc((len + 2) * sizeof(char));
	if (!sub)
		return (NULL);
	while (s[start + i] != '\0' && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '/';
	i++;
	sub[i] = '\0';
	return (sub);
}
