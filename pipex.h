/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:07:04 by asauafth          #+#    #+#             */
/*   Updated: 2025/11/10 12:00:05 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

/*******************/
/*     pipex.c     */
/*******************/
void	execute_command(char *cmd, char **env);
void	parent_process(int *fd, char **argv, char **env);
void	child_process(int *fd, char **argv, char **env);

/**************************/
/*        pipex_utils.c   */
/**************************/
int		ft_strcmp(char *s1, char *s2);
int		open_file(int fd, char *file);
char	*get_env(char *name, char **env);
void	full_free(char **str);
char	*find_path(char *cmd, char **env);

#endif