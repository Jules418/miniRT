/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:37:03 by lcamerly          #+#    #+#             */
/*   Updated: 2024/06/04 22:13:29 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	check_rgb_cone(char **tmp2)
{
	if (!tmp2 || len_split(tmp2) != 3)
		exit_error("Error\nMalloc failed in cone.c:32\nExiting...\n");
	while (*tmp2)
	{
		if (ft_atof(*tmp2) < 0 || ft_atof(*tmp2) > 255)
			exit_error("Cone color (RGB) must be between [0,255] ! \
            \nExiting...\n");
		tmp2++;
	}
}

/*
Cone:
co 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
∗ identifier: co
∗ x,y,z coordinates of the center of the cylinder: 50.0,0.0,20.6
* the cone direction: 0.0,0.0,1.0
∗ the angle diameter: 14.2 (in degrees) (0 < angle < 90)
∗ the cone height: 21.42
∗ R,G,B colors in range [0,255]: 10, 0, 255
*/
void	check_cone(char *s)
{
	char	**tmp;
	char	**tmp2;

	tmp = gc_split(s, ' ');
	if (!tmp || len_split(tmp) != 6)
		exit_error("Error\nMalloc failed in cone.c:29\nExiting...\n");
	tmp2 = gc_split(tmp[1], ',');
	if (!tmp2 || len_split(tmp2) != 3)
		exit_error("Error\nMalloc failed in cone.c:32\nExiting...\n");
	while (*tmp2)
		ft_atof(*tmp2++);
	tmp2 = gc_split(tmp[2], ',');
	if (!tmp2 || len_split(tmp2) != 3)
		exit_error("Error\nMalloc failed in cone.c:32\nExiting...\n");
	while (*tmp2)
		if (ft_atof(*tmp2) < -1 || ft_atof(*tmp2++) > 1)
			exit_error("Cone axis vector must be normalized ! \
            \nExiting...\n");
	if (ft_atof(tmp[3]) < 0 || ft_atof(tmp[3]) > 90)
		exit_error("Cone angle must be positive and inferior to \
		180 degrees!\nExiting...\n");
	if (ft_atof(tmp[4]) < 0)
		exit_error("Cone height must be positive !\nExiting...\n");
	tmp2 = gc_split(tmp[5], ',');
	check_rgb_cone(tmp2);
	printf("✅ Cone OK !\n");
}

void	init_cone(char *s, t_minirt *minirt)
{
	char	**tmp;
	char	**tmp2;
	t_cone	*c;

	tmp = gc_split(s, ' ');
	if (!tmp)
		exit_error("Error\nMalloc failed in cone.c:55\nExiting...\n");
	tmp2 = gc_split(tmp[1], ',');
	if (!tmp2)
		exit_error("Error\nMalloc failed in cone.c:58\nExiting...\n");
	c = malloc(sizeof(t_cone));
	if (!c)
		exit_error("Error\nMalloc failed in cone.c:61\nExiting...\n");
	c->pos = (t_vec3){ft_atof(tmp2[0]), ft_atof(tmp2[1]), ft_atof(tmp2[2])};
	c->angle = ft_atof(tmp[3]) * (2 * M_PI) / 360.f;
	c->height = ft_atof(tmp[4]);
	c->cos2 = cosf(c->angle) * cosf(c->angle);
	tmp2 = gc_split(tmp[2], ',');
	if (!tmp2)
		exit_error("Error\nMalloc failed in cone.c:66\nExiting...\n");
	c->dir = (t_vec3){ft_atof(tmp2[0]), ft_atof(tmp2[1]), ft_atof(tmp2[2])};
	create_cone_obj(minirt, c, tmp[5]);
}

void	create_cone_obj(t_minirt *minirt, t_cone *c, char *s)
{
	t_objects	*o;
	char		**tmp2;

	tmp2 = gc_split(s, ',');
	if (!tmp2)
		exit_error("Error\nMalloc failed in cone.c:71\nExiting...\n");
	o = create_obj(cone, c, (t_vec3){ft_atof(tmp2[0]) / 255, ft_atof(tmp2[1])
			/ 255, ft_atof(tmp2[2]) / 255});
	ft_lstadd_back(&minirt->scene->objects, ft_lstnew(o));
}
