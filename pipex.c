/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:06:19 by asauafth          #+#    #+#             */
/*   Updated: 2025/11/09 17:10:57 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <errno.h>
#include <string.h>
#include <stdio.h>

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

void		execute_command(char *cmd, char **env)
{
    char *sh_argv[4];

    if (!cmd)
        exit(EXIT_FAILURE);
    sh_argv[0] = "sh";
    sh_argv[1] = "-c";
    sh_argv[2] = cmd;
    sh_argv[3] = NULL;
   if (execve("/bin/sh", sh_argv, env) == -1)
   {
		ft_printf("Error");
	    exit(EXIT_FAILURE);
   }
    exit(0);
}

void	parent_process(int *fd, char **argv, char **env)
{
	int file_d;
	int ret;

	file_d = open_file(1, argv[4]);
	ret = dup2(file_d, 1);
	if (ret == -1)
	{
		close(file_d);
		close(fd[0]);
		close(fd[1]);
		exit(EXIT_FAILURE);
	}
	ret = dup2(fd[0], 0);
	if (ret == -1)
	{
		close(file_d);
		close(fd[0]);
		close(fd[1]);
		exit(EXIT_FAILURE);
	}
	close(file_d);
	close(fd[1]);
	execute_command(argv[3], env);
}

void	child_process(int *fd, char **argv, char **env)
{
	int	file_d;
	int ret;

	file_d = open_file(0, argv[1]);
	ret = dup2(file_d, 0);
	if (ret == -1)
	{
		close(file_d);
		close(fd[0]);
		close(fd[1]);
		exit(EXIT_FAILURE);
	}
	ret = dup2(fd[1], 1);
	if (ret == -1)
	{
		close(file_d);
		close(fd[0]);
		close(fd[1]);
		exit(EXIT_FAILURE);
	}
	close(file_d);
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
