/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:48:54 by lcamerly          #+#    #+#             */
/*   Updated: 2024/05/17 15:29:28 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	pre_read(int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			i++;
		free(line);
	}
	close_file(fd);
	return (i);
}

char	**read_file(int fd, int nb_lines)
{
	char	**res;
	char	*line;
	int		i;

	i = 0;
	res = malloc(sizeof(char *) * nb_lines);
	if (!res)
		exit(1);
	while (i < nb_lines)
	{
		line = get_next_line(fd);
		res[i] = line;
		i++;
	}
	res[i] = NULL;
	close_file(fd);
	return (res);
}
