/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:53:22 by lcamerly          #+#    #+#             */
/*   Updated: 2024/05/26 20:39:47 by lcamerly         ###   ########.fr       */
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
	fd = open_file(av[1]);
	res = read_file(fd, count);
	if (!res)
		exit(1);
	close(fd);
	return (res);
}
int check_line(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (ft_strncmp(s[i], "A", 1))
			check_ambientlight(s[i]);
		else if (ft_strncmp(s[i], "C", 1))
			check_camera(s[i]);
		else if (ft_strncmp(s[i], "L", 1))
			check_light(s[i]);
		else if (ft_strncmp(s[i], "sp", 2))
			check_sphere(s[i]);
		else if (ft_strncmp(s[i], "pl", 2))
			check_plane(s[i]);
		else if (ft_strncmp(s[i], "cy", 2))
			check_cylinder(s[i]);
		else if (ft_strncmp(s[i], "sp", 2))
			check_sphere(s[i]);
		else if (ft_strncmp(s[i], "co", 2))
			check_co(s[i]);
		else
			exit_error();
		i++;
	}
}
int check_ambientlight(char *s)
{
	char **tmp;
	int i;

	i = 0;
	tmp = ft_split(s, ' ');
	if (ft_strncmp(tmp[0], "A", 1))
		exit_error();
	if (ft_atof(tmp[1]) < 0 || ft_atof(tmp[1]) > 1)
		exit_error();
	tmp = ft_split(tmp[2], ',');
	while (tmp[i])
	{
		if (ft_atof(tmp[i]) < 0 || ft_atof(tmp[i]) > 255)
			exit_error();
		i++;
	}
}
