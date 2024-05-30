/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 00:45:56 by lcamerly          #+#    #+#             */
/*   Updated: 2024/05/30 00:30:25 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
Sphere:
sp 0.0,0.0,20.6 12.6 10,0,255
- identifier: sp
- x,y,z coordinates of the sphere center: 0.0,0.0,20.6
- the sphere diameter: 12.6
- R,G,B colors in range [0-255]: 10, 0, 255
*/

void	check_sphere(char *s)
{
	char	**tmp;
	char	**tmp2;

	tmp = gc_split(s, ' ');
	if (!tmp)
		exit_error("Error\nMalloc failed in sphere.c:27\nExiting...\n");
	tmp2 = gc_split(tmp[1], ',');
	if (!tmp2)
		exit_error("Error\nMalloc failed in sphere.c:30\nExiting...\n");
	while (*tmp2)
		ft_atof(*tmp2++);
	if (ft_atof(tmp[2]) < 0)
		exit_error("Sphere diameter must be positive !\nExiting...\n");
	tmp2 = gc_split(tmp[3], ',');
	while (*tmp2)
	{
		if (ft_atof(*tmp2) < 0 || ft_atof(*tmp2) > 255)
			exit_error("Sphere color (RGB) must be between [0,255] ! \
            \nExiting...\n");
		tmp2++;
	}
	printf("✅ Sphere OK !\n");
}

void	init_sphere(char *s, t_minirt *minirt)
{
	char		**tmp;
	char		**tmp2;
	t_sphere	*sp;
	t_objects	*o;

	tmp = gc_split(s, ' ');
	if (!tmp)
		exit_error("Error\nMalloc failed in sphere.c:55\nExiting...\n");
	tmp2 = gc_split(tmp[1], ',');
	if (!tmp2)
		exit_error("Error\nMalloc failed in sphere.c:58\nExiting...\n");
	sp = malloc(sizeof(t_sphere));
	if (!sp)
		exit_error("Error\nMalloc failed in sphere.c:61\nExiting...\n");
	sp->pos = (t_vec3){ft_atof(*tmp2), ft_atof(*(tmp2 + 1)), ft_atof(*(tmp2
				+ 2))};
	sp->radius = ft_atof(tmp[2]);
	tmp2 = gc_split(tmp[3], ',');
	if (!tmp2)
		exit_error("Error\nMalloc failed in sphere.c:66\nExiting...\n");
	o = create_obj(sphere, sp, (t_vec3){ft_atof(*tmp2) / 255, ft_atof(*(tmp2
					+ 1)) / 255, ft_atof(*(tmp2 + 2)) / 255});
	ft_lstadd_back(&minirt->scene->objects, ft_lstnew(o));
}

t_objects	*create_obj(t_type type, void *obj, t_vec3 color)
{
	t_objects	*o;

	o = malloc(sizeof(t_objects));
	o->obj_type = type;
	o->obj = obj;
	o->color = color;
	return (o);
}
