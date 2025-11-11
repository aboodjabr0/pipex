/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 23:29:22 by asauafth          #+#    #+#             */
/*   Updated: 2025/11/11 01:35:59 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void		execute_command(char *cmd, char **env)
{
	char **split_cmd;
	char *path;

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

void here_doc_put_in(char **argv, int *fd)
{
    char *line;
    char *gnl_buffer;

    gnl_buffer = NULL;
    close(fd[0]);
    while (1)
    {
        line = get_next_line(0, &gnl_buffer);
        if (!line)
        {
            free(gnl_buffer);
            exit(EXIT_SUCCESS);
        }
        if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0
            && (line[ft_strlen(argv[2])] == '\n' || line[ft_strlen(argv[2])] == '\0'))
        {
            free(line);
            free(gnl_buffer);
            exit(EXIT_SUCCESS);
        }
        ft_putstr_fd(line, fd[1]);
        free(line);
    }
}

void here_doc(char **argv)
{
    int fd[2];
    pid_t pid;
    if (pipe(fd) == -1)
        exit(EXIT_FAILURE);
    pid = fork();
    if (pid == -1)
        exit(EXIT_FAILURE);
    if (pid == 0)
        here_doc_put_in(argv, fd);
    else
    {
        close(fd[1]);
        dup2(fd[0], 0);
        wait(NULL);
    }
}

void do_pipe(char *cmd, char **env)
{
    pid_t pid;
    int fd[2];

    if (pipe(fd) == -1)
        exit (EXIT_FAILURE);
    pid = fork();
    if (pid == -1)
        exit (EXIT_FAILURE);
    if (pid == 0)
    {
        close(fd[0]);
        dup2(fd[1], 1);
        execute_command(cmd, env);
    }
    else
    {
		close(fd[1]);
		dup2(fd[0], 0);
    }
}

int main(int argc, char **argv, char **env)
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
		fd_out = open_file(argv[argc - 1], 1);
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
		do_pipe(argv[i++], env);
	execute_final_command(argv[argc - 2], env, fd_out);
	return (0);
}

