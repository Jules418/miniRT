/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:09:59 by jbanacze          #+#    #+#             */
/*   Updated: 2024/04/19 03:45:39 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

int	vec_to_rgb(t_vec3 u)
{
	int	r;
	int	g;
	int	b;
	
	r = (int)(u.x * 255.f);
	g = (int)(u.y * 255.f);
	b = (int)(u.z * 255.f);
	return ((r << 16) | (g << 8) | b);
}

void	print_vec(t_vec3 v)
{
	printf("{%f, %f, %f}\n", v.x, v.y, v.z);
}

t_ray	get_ray(t_scene scene, int x, int y)
{
	t_ray	ray;
	t_vec3	forward;
	t_vec3	up;
	t_vec3	right;

	forward = scene->cam.forward;
	up = scene->cam.up;
	right = scene->cam.right;
	ray.origin = scene->cam.pos;
	ray.dir = scale(forward, scene->d_to_screen);
	ray.dir = add(ray.dir, scale(right, ((float)x * 2.f) / scene->width - 1.f));
	ray.dir = add(ray.dir, scale(up, ((float)y * 2.f) / scene->height - 1.f));
	ray.dir = normalized(ray.dir);
	return (ray);
}

float	cast_ray(t_ray ray, t_objects *obj)
{
	if (obj->obj_type == (t_type)sphere)
		return (sphere_intersection(ray, *(t_sphere*)obj->obj));
	if (obj->obj_type == (t_type)plane)
		return (plane_intersection(ray, *(t_plane*)obj->obj));
	if (obj->obj_type == (t_type)cylinder)
		return (cylinder_intersection(ray, *(t_cylinder*)obj->obj));
	return (-1.f);
}

t_hitpoint	get_hitpoint(t_scene scene, t_ray ray)
{
	t_hitpoint	hit;
	float		d;
	int			i;

	i = -1;
	hit.obj = NULL;
	hit.d = 999999999.f;
	while (++i < scene->nb_objects)
	{
		d = cast_ray(ray, scene->objects + i);
		if ((d != -1.f) && (d < hit.d))
		{
			hit.d = d;
			hit.obj = scene->objects + i;
			hit.hitpos = move_ray(ray, d);
		}
	}
	return (hit);
}

t_vec3	compute_pixel(t_scene scene, int x, int y)
{
	t_ray		ray;
	t_hitpoint	hit;
	t_vec3		color;
	t_vec3		to_light;
	t_vec3		normal_vect;

	ray = get_ray(scene, x, y);
	hit = get_hitpoint(scene, ray);
	if ((hit.d == -1.f) || (hit.obj == NULL))
		return ((t_vec3){0.f, 0.f, 0.f});
	color = hit.obj->color;
	to_light = normalized(sub(scene->light.pos, hit.hitpos));
	normal_vect = normal_sphere(*(t_sphere*)(hit.obj->obj), hit.hitpos);
	color = scale(color, fmaxf(0.2f, dot(to_light, normal_vect)));
	return (color);
}

void	render_scene(t_minirt *minirt)
{
	t_scene	scene;
	int		x;
	int		y;
	int		color;

	scene = minirt->scene;
	if (!scene || !(scene->should_render))
		return ;
	scene->should_render = 0;
	x = 0;
	while (x < scene->width)
	{
		y = 0;
		while (y < scene->height)
		{
			color = vec_to_rgb(compute_pixel(scene, x, y));
			my_mlx_pixel_put(&minirt->img, x, y, color);
			y++;
		}
		x++;
	}
	printf("DONE\n");
	return ;
}
