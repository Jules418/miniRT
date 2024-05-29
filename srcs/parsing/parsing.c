/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:53:22 by lcamerly          #+#    #+#             */
/*   Updated: 2024/05/28 19:33:18 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void check_chars(char **s)
{
	int i;
	int j;

	i = 0;
	while (s[i])
	{
		j = 2;
		while (s[i][j])
		{
			if (s[i][j] != ' ' && s[i][j] != ',' && s[i][j] != '.' && s[i][j] != '-' && s[i][j] != '\n' && !ft_isdigit(s[i][j]))
				exit_error("Error\nInvalid character in file\n");
			j++;
		}
		i++;
	}
}

char	**parsing(char **av)
{
	int		fd;
	int		count;
	char	**res;

	fd = open_file(av[1]);
	count = pre_read(fd);
	fd = open_file(av[1]);
	res = read_file(fd, count);
	close(fd);
	check_chars(res);
	return (res);
}
// int check_line(char **s)
// {
// 	int i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (ft_strncmp(s[i], "A", 1))
// 			check_ambientlight(s[i]);
// 		else if (ft_strncmp(s[i], "C", 1))
// 			check_camera(s[i]);
// 		else if (ft_strncmp(s[i], "L", 1))
// 			check_light(s[i]);
// 		else if (ft_strncmp(s[i], "sp", 2))
// 			check_sphere(s[i]);
// 		else if (ft_strncmp(s[i], "pl", 2))
// 			check_plane(s[i]);
// 		else if (ft_strncmp(s[i], "cy", 2))
// 			check_cylinder(s[i]);
// 		else if (ft_strncmp(s[i], "sp", 2))
// 			check_sphere(s[i]);
// 		else if (ft_strncmp(s[i], "co", 2))
// 			check_co(s[i]);
// 		else
// 			exit_error();
// 		i++;
// 	}
// }

