/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:41:52 by nvideira          #+#    #+#             */
/*   Updated: 2022/06/02 01:13:49 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		bridge[2];
	pid_t	pid1;
	pid_t	pid2;
	char	**cmds;
	char	*path;
	int		here_doc;
}	t_pipex;

int		ft_strichr(const char *s, int start, int c);
char	*ft_substring(char const *s, unsigned int start, size_t len);
char	*find_path(char *cmd, char **envp);

#endif
