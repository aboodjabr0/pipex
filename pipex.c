/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:06:19 by asauafth          #+#    #+#             */
/*   Updated: 2025/11/05 14:47:11 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(int *fd, char **argv, char **env)
{
	int fd;
	
	fd = open_file(1, argv[4]);
	dup2(fd, 1);
	dup2(fd[0], 0);
	
}

void	child_process(int *fd, char **argv, char **env)
{
	int	fd;

	fd = open_file(0, argv[1]);
	dup2(fd, 0);
	dup2(fd[1], 1);
	
}

int	main(int argc, char **argv, char **env)
{
    int		fd[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_printf("Error the usage is :\n");
		ft_printf("./pipex < file1 cmd1 | cmd2 > file2 ");
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
