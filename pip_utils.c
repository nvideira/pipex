/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvideira <nvideira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:45:09 by nvideira          #+#    #+#             */
/*   Updated: 2022/06/07 00:33:36 by nvideira         ###   ########.fr       */
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

char	*ft_substring(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!len || ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s))
	{
		len = ft_strlen(s);
		return (ft_substr(s, start, len));
	}
	sub = malloc((len + 2) * sizeof(char));
	if (!sub)
		return (NULL);
	while (s[start + i] != '\0' && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '/';
	i++;
	sub[i] = '\0';
	return (sub);
}

char	*join_strings(char *path, int j, char *cmd)
{
	char	*dir;
	char	*ret_path;

	dir = ft_substring(path, j, ft_strichr(path, j, ':') - j);
	ret_path = ft_strjoin(dir, cmd);
	free(dir);
	return (ret_path);
}

char	*find_path(char *cmd, char **envp)
{
	int		j;
	char	*path;
	char	*ret_path;

	j = 0;
	while (envp[j] && ft_strncmp(envp[j], "PATH=", 5))
		j++;
	path = envp[j];
	while (path[j] && ft_strichr(path, j, ':') > -1)
	{
		ret_path = join_strings(path, j, cmd);
		if (!access(ret_path, F_OK))
			return (ret_path);
		free(ret_path);
		j += ft_strichr(path, j, ':') - j + 1;
	}
	if (path[j] && ft_strichr(path, j, ':') < 0)
	{
		ret_path = join_strings(path, j, cmd);
		if (!access(ret_path, F_OK))
			return (ret_path);
		free(ret_path);
	}
	return (0);
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
