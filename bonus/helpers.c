/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 00:46:41 by asauafth          #+#    #+#             */
/*   Updated: 2025/11/11 01:36:08 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void print_error(int n)
{
    if (n == 1)
        ft_putstr_fd("Error: too few arguments\n", 2);
    if (n == 2)
        ft_putstr_fd("Error: limiter not detected\n", 2);
    exit(EXIT_FAILURE);
}

void	execute_final_command(char *cmd, char **env, int fd_out)
{
	pid_t	final_pid;

	final_pid = fork();
	if (final_pid == -1)
		exit(EXIT_FAILURE);
	if (final_pid == 0)
	{
		dup2(fd_out, 1);
		execute_command(cmd, env);
	}
	else
	{
		close(fd_out);
		while (wait(NULL) > 0)
			;
	}
}