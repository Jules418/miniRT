/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:18:03 by jbanacze          #+#    #+#             */
/*   Updated: 2024/05/30 01:33:06 by jules            ###   ########.fr       */
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
		else if (check_name(map[i], "sp"))
			check_sphere(map[i]);
		else if (check_name(map[i], "pl"))
			check_plane(map[i]);
		else if (check_name(map[i], "cy"))
			check_cylinder(map[i]);
		else if (check_name(map[i], "sp"))
			check_sphere(map[i]);
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
		i++;
	}
}

void	init_scene(char **map, t_minirt *minirt)
{
	t_scene	t;

	check_everything(map);
	t = malloc(sizeof(struct s_scene));
	if (!t)
		exit_error("Error\nMalloc failed in test_scene.c:184\nExiting...\n");
	t->should_render = 1;
	t->height = TEMP_HEIGHT;
	t->width = TEMP_WIDTH;
	t->lights = NULL;
	minirt->scene = t;
	minirt->scene->objects = NULL;
	init_everything(map, minirt);
}
