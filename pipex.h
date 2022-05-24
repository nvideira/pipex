/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:41:52 by nvideira          #+#    #+#             */
/*   Updated: 2022/05/24 18:26:36 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		bridge[2];
	pid_t	pid1;
	pid_t	pid2;
	char	**cmds;
	char	*path;
	int		read;
}	t_pipex;

int	ft_strichr(const char *s, int start, int c);

#endif
