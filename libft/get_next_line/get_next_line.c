/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:55:12 by lcamerly          #+#    #+#             */
/*   Updated: 2024/01/18 14:44:09 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_read_line(int fd, char **temp, char **stash)
{
	int		read_byte;
	char	*buff;

	read_byte = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return ;
	while (read_byte > 0)
	{
		read_byte = read(fd, buff, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free_strs(&buff, stash, temp);
			return ;
		}
		buff[read_byte] = '\0';
		*temp = ft_strdup_gnl(*stash);
		free_strs(stash, NULL, NULL);
		*stash = ft_strjoin(*temp, buff);
		free_strs(temp, NULL, NULL);
		if (has_newline_inside(*stash) == 1)
			break ;
	}
	free_strs(&buff, NULL, NULL);
}

char	*ft_get_before_newline(const char *s)
{
	char	*res;
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] != '\0' && s[i] == '\n')
		i++;
	res = ft_malloc_zero(i + 1, sizeof * res);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

char	*ft_get_after_newline(const char *s)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s && s[j])
		j++;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] != '\0' && s[i] == '\n')
		i++;
	res = ft_malloc_zero((j - i) + 1, sizeof * res);
	if (!res)
		return (NULL);
	j = 0;
	while (s[i + j])
	{
		res[j] = s[i + j];
		j++;
	}
	return (res);
}

char	*ft_parse_line(char **stash, char **temp)
{
	char	*line;

	*temp = ft_strdup_gnl(*stash);
	free_strs(stash, NULL, NULL);
	*stash = ft_get_after_newline(*temp);
	line = ft_get_before_newline(*temp);
	free_strs(temp, NULL, NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;
	char		*temp;

	line = NULL;
	temp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
	{
		free_strs(&stash[fd], NULL, NULL);
		return (NULL);
	}
	ft_read_line(fd, &temp, &stash[fd]);
	if (stash[fd] != NULL && *stash[fd] != '\0')
		line = ft_parse_line(&stash[fd], &temp);
	if (!line || *line == '\0')
	{
		free_strs(&line, &temp, &stash[fd]);
		return (NULL);
	}
	free_strs(&temp, NULL, NULL);
	return (line);
}
