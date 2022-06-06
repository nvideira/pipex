/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:24:59 by nvideira          #+#    #+#             */
/*   Updated: 2022/06/07 00:33:51 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	heredoc(t_pipex pipex, char *limiter)
{
	char	*here;
	int		file;

	file = open(".heredoc_tmp", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (file < 0)
		perror("here_doc");
	while (1)
	{
		write(1, "heredoc> ", 9);
		here = get_next_line(0);
		if (!ft_strncmp(here, limiter, ft_strlen(limiter)))
			break ;
		write(file, here, ft_strlen(here));
		free(here);
	}
	free(here);
	close(file);
	pipex.infile = open(".heredoc_tmp", O_RDONLY);
	if (pipex.infile < 0)
	{
		unlink(".heredoc_tmp");
		perror("here_doc");
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
		dup2(pipex.outfile, STDOUT_FILENO);
	else
		dup2(pipex.bridge[1], STDOUT_FILENO);
	close(pipex.bridge[1]);
	pipex.cmds = ft_split(cmd, ' ');
	pipex.path = find_path(pipex.cmds[0], envp);
	execve(pipex.path, pipex.cmds, envp);
}

void	decide(int i, t_pipex pipex, char **argv, char **envp)
{
	if (i - pipex.here_doc == 2)
		ft_pipex(pipex, argv[i], envp, 1);
	else if (i - pipex.here_doc == pipex.argc - 2)
		ft_pipex(pipex, argv[i], envp, 2);
	else
		ft_pipex(pipex, argv[i], envp, 0);
}

void	parent(t_pipex pipex)
{
	dup2(pipex.bridge[0], STDIN_FILENO);
	close(pipex.bridge[0]);
	close(pipex.bridge[1]);
	wait(NULL);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		i;

	if (argc < 5)
		return (ft_printf("Please insert at least 4 arguments.\n"));
	pipex.outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	pipex.infile = get_infile(pipex, argv);
	pipex.argc = argc;
	i = 1 + pipex.here_doc;
	while (++i < argc - 1)
	{
		if (pipe(pipex.bridge) < 0)
			perror("Piping");
		pipex.pid1 = fork();
		if (pipex.pid1 == 0)
			decide (i, pipex, argv, envp);
		else
			parent(pipex);
	}
	close(pipex.infile);
	close(pipex.outfile);
	if (pipex.here_doc == 1)
		unlink(".heredoc_tmp");
}
