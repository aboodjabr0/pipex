/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:06:19 by asauafth          #+#    #+#             */
/*   Updated: 2025/11/11 17:25:40 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(void)
{
	ft_putstr_fd("Error the usage is :\n", 2);
	ft_putstr_fd("./pipex < file1 cmd1 | cmd2 > file2\n ", 2);
	exit(EXIT_FAILURE);
}

void	execute_command(char *cmd, char **env)
{
	char	**split_cmd;
	char	*path;

	split_cmd = ft_split(cmd, ' ');
	if (!split_cmd || !split_cmd[0])
	{
		ft_putstr_fd("command not found\n", 2);
		full_free(split_cmd);
		exit(EXIT_FAILURE);
	}
	path = find_path(split_cmd[0], env);
	if (!path)
	{
		ft_putstr_fd(split_cmd[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		full_free(split_cmd);
		exit(EXIT_FAILURE);
	}
	if (execve(path, split_cmd, env) == -1)
	{
		free(path);
		full_free(split_cmd);
		exit(EXIT_FAILURE);
	}
}

void	parent_process(int *fd, char **argv, char **env)
{
	int	file_d;

	file_d = open_file(1, argv[4]);
	if (dup2(file_d, 1) == -1)
		exit(EXIT_FAILURE);
	close(file_d);
	if (dup2(fd[0], 0) == -1)
		exit(EXIT_FAILURE);
	close(fd[0]);
	close(fd[1]);
	execute_command(argv[3], env);
}

void	child_process(int *fd, char **argv, char **env)
{
	int	file_d;

	file_d = open_file(0, argv[1]);
	if (dup2(file_d, 0) == -1)
		exit(EXIT_FAILURE);
	close(file_d);
	if (dup2(fd[1], 1) == -1)
		exit(EXIT_FAILURE);
	close(fd[0]);
	close(fd[1]);
	execute_command(argv[2], env);
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		print_error();
	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);
	pid1 = fork();
	if (pid1 == -1)
		exit(EXIT_FAILURE);
	if (pid1 == 0)
		child_process(fd, argv, env);
	pid2 = fork();
	if (pid2 == -1)
		exit(EXIT_FAILURE);
	if (pid2 == 0)
		parent_process(fd, argv, env);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
