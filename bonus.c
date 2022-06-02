/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:24:59 by nvideira          #+#    #+#             */
/*   Updated: 2022/06/02 04:32:44 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	heredoc(t_pipex pipex, char *limiter)
{
	char	*here;

	pipex.infile = open(".heredoc_tmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex.infile < 0)
		perror("here_doc");
	while (1)
	{
		write(1, "heredoc> ", 9);
		here = get_next_line(0);
		if (!ft_strncmp(here, limiter, ft_strlen(limiter)))
			break ;
		write(pipex.infile, &here, ft_strlen(here));
		write(pipex.infile, "\n", 1);
		free(here);
	}
	free(here);
}

void	get_infile(t_pipex pipex, char **argv)
{
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		pipex.here_doc = 1;
		heredoc(pipex, argv[2]);
	}
	else
	{
		pipex.here_doc = 0;
		pipex.infile = open(argv[1], O_RDONLY);
		if (pipex.infile < 0)
			perror("Infile");
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
		return (ft_printf("Please insert at least 4 arguments.\n"));
	get_infile(pipex, argv[1]);
	pipex.outfile = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	
}
