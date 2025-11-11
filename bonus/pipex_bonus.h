/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 23:29:34 by asauafth          #+#    #+#             */
/*   Updated: 2025/11/11 01:36:43 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"

/****************************************/
/*          gnl && error_handling.c     */
/****************************************/
void print_error(int n);
void	execute_final_command(char *cmd, char **env, int fd_out);
char	*get_next_line(int fd, char **buff_ptr);

/*******************************/
/*          pipex_bonus.c      */
/*******************************/
void do_pipe(char *cmd, char **env);
void here_doc(char **argv);
void here_doc_put_in(char **argv, int *fd);
void		execute_command(char *cmd, char **env);


/*******************************/
/*       pipex_utils_bonus.c   */
/*******************************/
int	ft_strcmp(char *s1, char *s2);
int	open_file(char *file, int fd);
char *get_env(char *name, char **env);
void	full_free(char **str);
char *find_path(char *cmd, char **env);

#endif