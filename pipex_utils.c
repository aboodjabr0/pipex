/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:00:07 by asauafth          #+#    #+#             */
/*   Updated: 2025/11/09 15:57:12 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (!s1)
		return (1);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	open_file(int fd, char *file)
{
	int	returned_fd;

	if (fd == 0)
		returned_fd = open(file, O_RDONLY);
	else if (fd == 1)
		returned_fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (returned_fd == -1)
		exit(EXIT_FAILURE);
	return (returned_fd);
}

char *get_env(char *name, char **env)
{
	int i;
	size_t len;

	if (!name || !env)
		return (NULL);
	len = ft_strlen(name);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], name, len) == 0 && env[i][len] == '=')
			return (env[i] + len + 1);
		i++;
	}
	return (NULL);
}
void	full_free(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char *find_path(char *cmd, char **env)
{
	int	i;
	char *exec;
	char **fullpath;
	char *path_needed;

	if (!get_env("PATH", env))
		return (NULL);
	fullpath = ft_split(get_env("PATH", env), ':');
	if (!fullpath)
		return (NULL);
	i = -1;
	while (fullpath[++i])
	{
		path_needed = ft_strjoin(fullpath[i], "/");
		exec = ft_strjoin(path_needed, cmd);
		free(path_needed);
		if (access(exec, F_OK | X_OK) == 0)
		{
			full_free(fullpath);
			return (exec);
		}
		free(exec);
	}
	full_free(fullpath);
	return (NULL);
}
