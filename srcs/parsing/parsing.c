/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:53:22 by lcamerly          #+#    #+#             */
/*   Updated: 2024/05/17 16:09:53 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	**parsing(char **av)
{
	int		fd;
	int		count;
	char	**res;

	fd = open_file(av[1]);
	count = pre_read(fd);
	res = malloc(sizeof(char *) * count + 1);
	if (!res)
		exit(1);
	fd = open_file(av[1]);
	res = read_file(fd, count);
	close_file(fd);
	return (res);
}
