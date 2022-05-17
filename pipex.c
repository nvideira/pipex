/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 02:51:01 by nvideira          #+#    #+#             */
/*   Updated: 2022/05/16 17:55:19 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**parse_it(char **argv)
{
	t_pipex	pipex;

	
}

void	ft_pipex(int file1, int file2, char **argv, char **envp)
{
	t_pipex	pipex;

	if (pipe(pipex.bridge) < 0)
		error_handler();
	pipex.child = fork();
	if (pipex.child < 0)
		error_handler();
	if (!pipex.child)
	{
			
	}
}
/*./pipex infile cmd1 cmd2 outfile*/

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (ft_printf("Please insert exactly 4 arguments.\n"));
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
	{
		perror("Infile");
		return (-1);
	}
	pipex.outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 766);
	if (pipex.outfile < 0)
	{
		perror("Outfile");
		return (-1);
	}
	ft_pipex(pipex.infile, pipex.outfile, argv, envp);
	
}
