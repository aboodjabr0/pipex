/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 23:29:22 by asauafth          #+#    #+#             */
/*   Updated: 2025/11/11 18:21:39 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	read_here_doc_input(char *delimiter, int write_fd)
{
	char	*line;
	char	*gnl_buffer;

	gnl_buffer = NULL;
	while (1)
	{
		line = get_next_line(0, &gnl_buffer);
		if (!line)
		{
			free(gnl_buffer);
			exit(EXIT_SUCCESS);
		}
		if (is_delimiter(line, delimiter))
		{
			free(line);
			free(gnl_buffer);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd(line, write_fd);
		free(line);
	}
}

void	here_doc(char **argv)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		close(fd[0]);
		read_here_doc_input(argv[2], fd[1]);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
}

void	fork_and_pipe(char *cmd, char **env)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
	{
		close(fd[0]);
		if (dup2(fd[1], 1) == -1)
			exit(EXIT_FAILURE);
		close(fd[1]);
		execute_command(cmd, env);
	}
	else
	{
		close(fd[1]);
		if (dup2(fd[0], 0) == -1)
			exit(EXIT_FAILURE);
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
}

int	main(int argc, char **argv, char **env)
{
	int	fd_in;
	int	fd_out;
	int	i;

	if (argc < 5)
		print_error(1);
	if (!ft_strcmp(argv[1], "here_doc"))
	{
		if (argc < 6)
			print_error(2);
		i = 3;
		fd_out = open_file(argv[argc - 1], 2);
		here_doc(argv);
	}
	else
	{
		i = 2;
		fd_in = open_file(argv[1], 0);
		fd_out = open_file(argv[argc - 1], 1);
		dup2(fd_in, 0);
	}
	while (i < argc - 2)
		fork_and_pipe(argv[i++], env);
	execute_final_command(argv[argc - 2], env, fd_out);
	return (0);
}
