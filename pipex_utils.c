/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:00:07 by asauafth          #+#    #+#             */
/*   Updated: 2025/11/05 14:07:27 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(int fd, char *file)
{
	int	returned_fd;

	if (fd == 0)
		returned_fd = open(file, O_RDONLY, 0777);
	if (fd == 1)
		returned_fd = open(file, O_WRONLY | O_CREAT, 0777);
	if (fd == -1)
		exit(EXIT_FAILURE);
	return(returned_fd);
}