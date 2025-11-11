/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:10:23 by asauafth          #+#    #+#             */
/*   Updated: 2025/11/11 00:32:25 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*ft_join(char *full_file, char *s_chunk)
{
	char	*tmp;

	if (!s_chunk)
		return (full_file);
	if (!full_file)
	{
		tmp = ft_strdup(s_chunk);
		if (!tmp)
			return (NULL);
		return (tmp);
	}
	tmp = ft_strjoin(full_file, s_chunk);
	free(full_file);
	if (!tmp)
		return (NULL);
	return (tmp);
}

static char	*read_file(int fd, char *full_file, int *bytes_read)
{
	char	*s_chunk;

	s_chunk = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!s_chunk)
	{
		free(full_file);
		return (NULL);
	}
	while ((full_file == NULL || !ft_strchr(full_file, '\n')) && *bytes_read > 0)
	{
		*bytes_read = read(fd, s_chunk, BUFFER_SIZE);
		if (*bytes_read == -1)
		{
			free(s_chunk);
			free(full_file);
			return (NULL);
		}
		if (*bytes_read >= 0)
			s_chunk[*bytes_read] = '\0';
		full_file = ft_join(full_file, s_chunk);
		if (!full_file)
			break ;
	}
	free(s_chunk);
	return (full_file);
}

static char	*del_line(char *full_file)
{
	int		i;
	int		j;
	char	*new_buff;

	i = 0;
	if (!full_file)
		return (NULL);
	while (full_file[i] != '\0' && full_file[i] != '\n')
		i++;
	if (!full_file[i])
	{
		free (full_file);
		return (NULL);
	}
	new_buff = ft_calloc(ft_strlen(full_file) - i + 1, sizeof(char));
	if (!new_buff)
	{
		free(full_file);
		return (NULL);
	}
	j = 0;
	while (full_file[++i] != '\0')
		new_buff[j++] = full_file[i];
	free (full_file);
	return (new_buff);
}

static char	*read_1st_line(char *full_file)
{
	char	*line;
	int		i;

	i = 0;
	if (!full_file || full_file[i] == '\0')
		return (NULL);
	while (full_file[i] != '\0' && full_file[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (full_file[i] != '\0' && full_file[i] != '\n')
	{
		line[i] = full_file[i];
		i++;
	}
	if (full_file[i] != '\0' && full_file[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*get_next_line(int fd, char **buff_ptr)
{
	char		*line;
	int			bytes_read;

	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || !buff_ptr)
		return (NULL);
	*buff_ptr = read_file(fd, *buff_ptr, &bytes_read);
	if (!*buff_ptr)
		return (NULL);
	line = read_1st_line(*buff_ptr);
	*buff_ptr = del_line(*buff_ptr);
	if (!line)
	{
		free(line);
		free(*buff_ptr);
		*buff_ptr = NULL;
		return (NULL);
	}
	return (line);
}
