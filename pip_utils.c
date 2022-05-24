/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:45:09 by nvideira          #+#    #+#             */
/*   Updated: 2022/05/21 12:45:38 by nvideira         ###   ########.fr       */
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
