/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:18:03 by jbanacze          #+#    #+#             */
/*   Updated: 2024/05/28 14:52:40 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>
#include <stdio.h>

t_camera	test_cam(void)
{
	t_camera	cam;
	float		fov;

	fov = 60.f;
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
	l.pos = (t_vec3){0.f, 150.f, 100.f};
	return (l);
}

t_objects	test_object1(void)
{
	t_objects	o;
	t_sphere	*s;

	o.obj_type = (t_type)sphere;
	o.color = (t_vec3){1.f, 0.f, 0.f};
	s = malloc(sizeof(t_sphere));
	s->pos = (t_vec3){53.f, 0.f, 0.f};
	s->radius = 5.f;
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
	s->pos = (t_vec3){0.f, -20.f, 0.f};
	s->normal_vector = (t_vec3){0.f, 1.f, 0.f};
	o.obj = s;
	return (o);
}

t_objects	test_object3(void)
{
	t_objects	o;
	t_cylinder	*s;

	o.obj_type = (t_type) cylinder;
	o.color = (t_vec3){1.f, 0.f, 0.f};
	s = malloc(sizeof(t_cylinder));
	s->pos = (t_vec3){20.f, 0.f, -10.f};
	s->width = 4.f;
	s->height = 10.f;
	s->dir = normalized((t_vec3){1.f, 1.f, 1.f});
	o.obj = s;
	return (o);
}

t_objects	test_object4(void)
{
	t_objects	o;
	t_cone		*co;

	o.obj_type = (t_type) cone;
	o.color = (t_vec3){0.f, 0.f, 1.f};
	co = malloc(sizeof(t_cone));
	co->pos = (t_vec3){50.f, 0.f, 0.f};
	co->dir = normalized((t_vec3){0.f, -1.f, 0.f});
	co->angle = M_PI / 6.f;
	co->cos2 = powf(cos(co->angle), 2.f);
	co->height = 16.f;
	o.obj = co;
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
	t->height = TEMP_HEIGHT;
	t->width = TEMP_WIDTH;
	t->nb_objects = 2;
	t->light = test_light();
	t->objects[0] = test_object4();
	t->objects[1] = test_object2();
	// t->objects[2] = test_object4();
	t->d_to_screen = 1.f / (2.f * tanf(t->cam.fov / 2.f));
	t->ambient_light = scale((t_vec3){1.f, 1.f, 1.f}, 0.2f);
	return (t);
}
