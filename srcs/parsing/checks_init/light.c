/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 00:06:05 by lcamerly          #+#    #+#             */
/*   Updated: 2024/05/30 01:36:20 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
Light:
L -40.0,50.0,0.0 0.6 10,0,255
 - identifier: L
 - x,y,z coordinates of the light point: -40.0,50.0,0.0
 - the light brightness ratio in range [0.0,1.0]: 0.6
 - R,G,B colors in range [0-255]: 10, 0, 255
*/
void	check_light(char *s)
{
	char	**tmp;
	char	**tmp2;

	tmp = gc_split(s, ' ');
	if (!tmp)
		exit_error("Error\nMalloc failed in camera.c:19\nExiting...\n");
	tmp2 = gc_split(tmp[1], ',');
	if (!tmp2)
		exit_error("Error\nMalloc failed in camera.c:19\nExiting...\n");
	while (*tmp2)
		ft_atof(*tmp2++);
	if (ft_atof(tmp[2]) < 0.0 || ft_atof(tmp[2]) > 1.0)
		exit_error("Light brightness ratio must in range [0.0,1.0] !\
        \nExiting...\n");
	tmp2 = gc_split(tmp[3], ',');
	while (*tmp2)
	{
		if (ft_atof(*tmp2) < 0 || ft_atof(*tmp2) > 255)
			exit_error("Light color (RGB) must be between [0,255] !\
            \nExiting...\n");
		tmp2++;
	}
	printf("✅ Light OK !\n");
}

void	init_light(char *s, t_minirt *minirt)
{
	char	**tmp;
	char	**tmp2;
	t_light	*light;

	tmp = gc_split(s, ' ');
	if (!tmp)
		exit_error("Error\nMalloc failed in camera.c:56\nExiting...\n");
	tmp2 = gc_split(tmp[1], ',');
	if (!tmp2)
		exit_error("Error\nMalloc failed in camera.c:59\nExiting...\n");
	light = malloc(sizeof(t_light));
	if (!light)
		exit_error("Error\nMalloc failed in camera.c:62\nExiting...\n");
	light->pos = (t_vec3){ft_atof(*tmp2), ft_atof(*(tmp2 + 1)),
		ft_atof(*(tmp2 + 2))};
	light->brightness = ft_atof(tmp[2]);
	tmp2 = gc_split(tmp[3], ',');
	if (!tmp2)
		exit_error("Error\nMalloc failed in camera.c:63\nExiting...\n");
	light->color = (t_vec3){ft_atof(*tmp2) / 255, ft_atof(*(tmp2
				+ 1)) / 255, ft_atof(*(tmp2 + 2)) / 255};
	ft_lstadd_front(&minirt->scene->lights, ft_lstnew(light));
}
