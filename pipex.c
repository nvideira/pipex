/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 02:51:01 by nvideira          #+#    #+#             */
/*   Updated: 2022/05/09 03:51:02 by nvideira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*./pipex infile cmd1 cmd2 outfile*/
int	main(int argc, char **argv)
{
	t_pipex	pipex;

	if (argc != 5)
		return (ft_printf("Please insert exactly 4 arguments.\n"));
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		return (ft_printf("Error opening infile.\n"));
	pipex.outfile = open(argv[argc], O_CREAT | O_RDWR | O_TRUNC, 766);
	if (pipex.outfile < 0)
		return (ft_printf("Error opening outfile.\n"));
	
}
