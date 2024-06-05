/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:18:03 by jbanacze          #+#    #+#             */
/*   Updated: 2024/06/05 17:25:41 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_everything(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (check_name(map[i], "A"))
			check_ambientlight(map[i]);
		else if (check_name(map[i], "C"))
			check_camera(map[i]);
		else if (check_name(map[i], "L"))
			check_light(map[i]);
		else if (check_name(map[i], "pl"))
			check_plane(map[i]);
		else if (check_name(map[i], "cy"))
			check_cylinder(map[i]);
		else if (check_name(map[i], "sp"))
			check_sphere(map[i]);
		else if (check_name(map[i], "co"))
			check_cone(map[i]);
		else if (check_name(map[i], "\n"))
			;
		else
			exit_error("Error\nInvalid object name\nExiting...\n");
		i++;
	}
}

bool	check_name(char *line, char *name)
{
	int	i;

	i = 0;
	while (line[i] && name[i])
	{
		if (line[i] != name[i])
			return (false);
		i++;
	}
	return (true);
}

void	check_alc(char **map)
{
	int		i;
	int		alc[3];

	i = 0;
	ft_bzero(alc, 3 * sizeof(int));
	while (map[i])
	{
		if (check_name(map[i], "A"))
			alc[2]++;
		if (check_name(map[i], "L"))
			alc[1]++;
		if (check_name(map[i], "C"))
			alc[0]++;
		i++;
	}
	if (alc[2] > 1)
		exit_error("Error\nNot enough ambiant light\nExiting...\n");
	if (alc[2] < 1)
		exit_error("Error\nToo many ambiant light\nExiting...\n");
	if (alc[1] == 0)
		exit_error("Error\nNo light defined\nExiting...\n");
	if (alc[0] == 0)
		exit_error("Error\nNo camera defined\nExiting...\n");
}

void	init_everything(char **map, t_minirt *minirt)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (check_name(map[i], "A"))
			init_ambiantlight(map[i], minirt);
		else if (check_name(map[i], "C"))
			init_camera(map[i], minirt);
		else if (check_name(map[i], "L"))
			init_light(map[i], minirt);
		else if (check_name(map[i], "sp"))
			init_sphere(map[i], minirt);
		else if (check_name(map[i], "pl"))
			init_plane(map[i], minirt);
		else if (check_name(map[i], "cy"))
			init_cylinder(map[i], minirt);
		else if (check_name(map[i], "sp"))
			init_sphere(map[i], minirt);
		else if (check_name(map[i], "co"))
			init_cone(map[i], minirt);
		i++;
	}
}

void	init_scene(char **map, t_minirt *minirt)
{
	t_scene	t;

	check_everything(map);
	check_alc(map);
	t = malloc(sizeof(struct s_scene));
	if (!t)
		exit_error("Error\nMalloc failed in test_scene.c:184\nExiting...\n");
	t->should_render = 1;
	t->height = TEMP_HEIGHT;
	t->width = TEMP_WIDTH;
	t->lights = NULL;
	minirt->scene = t;
	minirt->scene->objects = NULL;
	minirt->scene->cameras = NULL;
	init_everything(map, minirt);
}
