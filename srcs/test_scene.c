/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:18:03 by jbanacze          #+#    #+#             */
/*   Updated: 2024/05/17 14:40:42 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>
#include <stdio.h>

t_camera	test_cam(void)
{
	t_camera	cam;
	float		fov;

	fov = 80.f;
	cam.pos = (t_vec3){0.f, 0.f, 0.f};
	cam.forward = (t_vec3){1.f, 0.f, 0.f};
	cam.up = (t_vec3){0.f, 1.f, 0.f};
	cam.right = (t_vec3){0.f, 0.f, 1.f};
	cam.fov = fov * 2.f * M_PI / 360.f;
	return (cam);
}

t_light	test_light(void)
{
	t_light	l;

	l.color = (t_vec3){1.f, 1.f, 1.f};
	l.brightness = 1.0f;
	l.pos = (t_vec3){0.f, -15.f, 10.f};
	return (l);
}

t_objects	test_object1(void)
{
	t_objects	o;
	t_sphere	*s;

	o.obj_type = (t_type)sphere;
	o.color = (t_vec3){1.f, 0.f, 0.f};
	s = malloc(sizeof(t_sphere));
	s->pos = (t_vec3){20.f, 0.f, 0.f};
	s->radius = 10.f;
	o.obj = s;
	return (o);
}

t_objects	test_object2(void)
{
	t_objects	o;
	t_plane		*s;

	o.obj_type = (t_type)plane;
	o.color = (t_vec3){1.f, 1.f, 1.f};
	s = malloc(sizeof(t_plane));
	s->pos = (t_vec3){0.f, -5.f, 0.f};
	s->normal_vector = (t_vec3){0.f, 1.f, 0.f};
	o.obj = s;
	return (o);
}

t_scene	test_scene(void)
{
	t_scene	t;

	t = malloc(sizeof(struct s_scene));
	if (!t)
		return (NULL);
	t->should_render = 1;
	t->cam = test_cam();
	t->height = 600;
	t->width = 800;
	t->nb_objects = 2;
	t->light = test_light();
	t->objects[0] = test_object1();
	t->objects[1] = test_object2();
	t->d_to_screen = 1.f / (2.f * tanf(t->cam.fov / 2.f));
	return (t);
}
