/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:24:59 by nvideira          #+#    #+#             */
/*   Updated: 2022/06/04 19:31:23 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	heredoc(t_pipex pipex, char *limiter)
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
	return (pipex.infile);
}

int	get_infile(t_pipex pipex, char **argv)
{
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		pipex.here_doc = 1;
		pipex.infile = heredoc(pipex, argv[2]);
	}
	else
	{
		pipex.here_doc = 0;
		if (!access(argv[1], F_OK))
			pipex.infile = open(argv[1], O_RDONLY);
		else
			perror("Infile");
	}
	return (pipex.infile);
}

void	ft_pipex(t_pipex pipex, char *cmd, char **envp, int flag)
{
	if (flag == 1)
	{
		close(pipex.bridge[0]);
		dup2(pipex.infile, STDIN_FILENO);
		dup2(pipex.bridge[1], STDOUT_FILENO);
	}
	else if (flag == 2)
	{
		close(pipex.bridge[1]);
		dup2(pipex.bridge[0], STDIN_FILENO);
		dup2(pipex.outfile, STDOUT_FILENO);
	}
	else
	{
		dup2(pipex.bridge[0], STDIN_FILENO);
		dup2(pipex.bridge[1], STDOUT_FILENO);
	}
	pipex.cmds = ft_split(cmd, ' ');
	pipex.path = find_path(pipex.cmds[0], envp);
	execve(pipex.path, pipex.cmds, envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		i;

	if (argc < 5)
		return (ft_printf("Please insert at least 4 arguments.\n"));
	pipex.outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	pipex.infile = get_infile(pipex, argv);
	i = 1 + pipex.here_doc;
	while (++i < argc - 1)
	{
		if (pipe(pipex.bridge) < 0)
			perror("Piping");
		pipex.pid1 = fork();
		if (pipex.pid1 == 0)
		{
			if (i - pipex.here_doc == 2)
				ft_pipex(pipex, argv[i], envp, 1);
			else if (i - pipex.here_doc == argc - 2)
				ft_pipex(pipex, argv[i], envp, 2);
			else
				ft_pipex(pipex, argv[i], envp, 0);
		}
		else
			wait(NULL);
	}
	close(pipex.infile);
	close(pipex.outfile);
}
