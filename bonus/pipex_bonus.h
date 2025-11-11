/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 23:29:34 by asauafth          #+#    #+#             */
/*   Updated: 2025/11/11 18:14:50 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

/**************************/
/*        helpers.c       */
/**************************/
void	print_error(int n);
void	execute_final_command(char *cmd, char **env, int fd_out);
char	*get_next_line(int fd, char **buff_ptr);
int		is_delimiter(char *line, char *delimiter);

/*******************************/
/*          pipex_bonus.c      */
/*******************************/
void	fork_and_pipe(char *cmd, char **env);
void	here_doc(char **argv);
void	read_here_doc_input(char *delimiter, int write_fd);
void	execute_command(char *cmd, char **env);

/*******************************/
/*       pipex_utils_bonus.c   */
/*******************************/
int		ft_strcmp(char *s1, char *s2);
int		open_file(char *file, int fd);
char	*get_env(char *name, char **env);
void	full_free(char **str);
char	*find_path(char *cmd, char **env);

#endif