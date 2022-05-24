/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 02:51:01 by nvideira          #+#    #+#             */
/*   Updated: 2022/05/24 18:54:53 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd, char **envp)
{
	int		i;
	int		j;
	char	*path;
	char	*dir;
	char	*ret_path;

	i = 0;
	j = 5;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (cmd);
	path = envp[i];
	printf("complete path is %s\n", path);
	while (path[j] && ft_strichr(path, j, ':') > -1)
	{
		dir = ft_substr(path, j, ft_strichr(path, j, ':') - j);
		printf("dir contains %s\n", dir);
		ret_path = ft_strjoin(dir, cmd);
		free(dir);
		//printf("path is %s\n", ret_path);
		if (access(path, F_OK) == 0)
			return (ret_path);
		free(ret_path);
		j += ft_strichr(path, j, ':') + 1;
	}
	return (cmd);
}

int	ft_pipex(t_pipex pipex, char **argv, char **envp)
{
	if (pipe(pipex.bridge) < 0)
		return (-1);
	pipex.pid1 = fork();
	if (pipex.pid1 < 0)
		return (-1);
	if (pipex.pid1 == 0)
	{
		printf("child1 pid is %d\n", pipex.pid1);
		close(pipex.bridge[0]);
		dup2(pipex.infile, STDIN_FILENO);
		//dup2(pipex.bridge[1], STDOUT_FILENO);
		pipex.path = find_path(argv[2], envp);
		//printf("path is %s\n", pipex.path);
		pipex.cmds = ft_split(argv[2], ' ');
		execve(pipex.path, pipex.cmds, envp);
	}
	if (pipe(pipex.bridge) < 0)
		return (-1);
	pipex.pid2 = fork();
	if (pipex.pid2 < 0)
		return (-1);
	if (pipex.pid2 == 0)
	{
		close(pipex.bridge[1]);
		pipex.path = find_path(argv[3], envp);
		dup2(pipex.bridge[0], STDIN_FILENO);
		dup2(pipex.outfile, STDOUT_FILENO);
		pipex.cmds = ft_split(argv[3], ' ');
		execve(pipex.path, pipex.cmds, envp);
	}
	wait(NULL);
	wait(NULL);
	return (0);
}
/*./pipex infile cmd1 cmd2 outfile*/

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
		return (ft_printf("Please insert at least 4 arguments.\n"));
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
	{
		perror("Infile");
		return (-1);
	}
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_RDWR | O_CREAT, 0644);
	if (pipex.outfile < 0)
	{
		perror("Outfile");
		return (-1);
	}
	ft_pipex(pipex, argv, envp);
	return (0);
}
