/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:06:19 by asauafth          #+#    #+#             */
/*   Updated: 2025/11/09 15:56:55 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void		execute_command(char *cmd, char **env)
{
	char **split_cmd;
	char *path;

	split_cmd = ft_split(cmd, ' ');
	if (!split_cmd || !split_cmd[0])
	{
		full_free(split_cmd);
		exit(EXIT_FAILURE);
	}
	path = find_path(split_cmd[0], env);
	if (!path)
	{
		ft_printf("%s: command not found\n", split_cmd[0]);
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
	int file_d;
	
	file_d = open_file(1, argv[4]);
	dup2(file_d, 1);
	dup2(fd[0], 0);
	close(fd[1]);
	execute_command(argv[3], env);
}

void	child_process(int *fd, char **argv, char **env)
{
	int	file_d;

	file_d = open_file(0, argv[1]);
	dup2(file_d, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	execute_command(argv[2], env);
}

int	main(int argc, char **argv, char **env)
{
    int		fd[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_printf("Error the usage is :\n");
		ft_printf("./pipex < file1 cmd1 | cmd2 > file2\n ");
		exit(EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);	
	if (pid == 0)
		child_process(fd, argv, env);
	parent_process(fd, argv, env);
}
