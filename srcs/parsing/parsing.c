/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:53:22 by lcamerly          #+#    #+#             */
/*   Updated: 2024/05/28 16:29:14 by lcamerly         ###   ########.fr       */
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

/*
** @brief Check if the ambiant light ratio is between 0 and 1
 and if the color is between 0 and 255
** @param char* s : Line to check
*/
void	check_ambientlight(char *s)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = gc_split(s, ' ');
	if (!tmp)
		exit_error("Error in a malloc (parsing.c:64)");
	if (ft_atof(tmp[1]) < 0.0 || ft_atof(tmp[1]) > 1.0)
		exit_error("Ambiant light ratio must in range [0.0,1.0] !\
		\nExiting...\n");
	tmp = gc_split(tmp[2], ',');
	if (!tmp)
		exit_error("Error in a malloc (parsing.c:69)");
	while (tmp[i])
	{
		if (ft_atof(tmp[i]) < 0 || ft_atof(tmp[i]) > 255)
			exit_error("Ambiant light color (RGB) must be between [0,255] !\
			\nExiting...\n");
		i++;
	}
	printf("✅ Ambiant light OK !\n");
}

void	init_ambiantlight(char *s, t_minirt *minirt)
{
	char	**tmp;
	char	**tmp2;

	tmp = gc_split(s, ' ');
	tmp2 = gc_split(tmp[2], ',');
	if (!tmp || !tmp2)
		exit_error("Error in a malloc (parsing.c:92 or 93)");
	minirt->scene->ambient_light = scale((t_vec3){(float)ft_atof(tmp2[0]) / 255,
			(float)ft_atof(tmp2[1]) / 255, (float)ft_atof(tmp2[2]) / 255},
			ft_atof(tmp[1]));
}
