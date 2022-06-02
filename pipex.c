/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 02:51:01 by nvideira          #+#    #+#             */
/*   Updated: 2022/06/02 01:29:20 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_cmd(t_pipex pipex, char *cmd, char **envp)
{
	dup2(pipex.infile, STDIN_FILENO);
	dup2(pipex.bridge[1], STDOUT_FILENO);
	pipex.cmds = ft_split(cmd, ' ');
	pipex.path = find_path(pipex.cmds[0], envp);
	if (!pipex.path)
		perror("Bad command");
	close(pipex.bridge[0]);
	execve(pipex.path, pipex.cmds, envp);
}

void	last_cmd(t_pipex pipex, char cmd, char **envp)
{
	dup2(pipex.bridge[0], STDIN_FILENO);
	dup2(pipex.outfile, STDOUT_FILENO);
	pipex.cmds = ft_split(cmd, ' ');
	pipex.path = find_path(pipex.cmds[0], envp);
	if (!pipex.path)
		perror("Bad command");
	close(pipex.bridge[1]);
	execve(pipex.path, pipex.cmds, envp);
}

int	ft_pipex(t_pipex pipex, char **argv, char **envp)
{
	if (pipe(pipex.bridge) < 0)
		perror("Piping failed");
	pipex.pid1 = fork();
	if (pipex.pid1 < 0)
		perror("Couldn't fork the child");
	if (pipex.pid1 == 0)
		first_cmd(pipex, argv[2], envp);
	close(pipex.bridge[1]);
	pipex.pid2 = fork();
	if (pipex.pid2 < 0)
		perror("Couldn't fork the child");
	if (pipex.pid2 == 0 && pipex.pid1 != 0)
		last_cmd(pipex, argv[3], envp);
	close(pipex.bridge[0]);
	wait(NULL);
	wait(NULL);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (ft_printf("Please insert at exactly 4 arguments.\n"));
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		perror("Infile");
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_RDWR | O_CREAT, 0644);
	if (pipex.outfile < 0)
		perror("Outfile");
	ft_pipex(pipex, argv, envp);
	close(pipex.infile);
	close(pipex.outfile);
	return (0);
}
