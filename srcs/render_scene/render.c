/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:09:59 by jbanacze          #+#    #+#             */
/*   Updated: 2024/04/21 02:01:43 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

int	vec_to_rgb(t_vec3 u)
{
	int	r;
	int	g;
	int	b;

	r = (int)(fminf(u.x * 255.f, 255.f));
	g = (int)(fminf(u.y * 255.f, 255.f));
	b = (int)(fminf(u.z * 255.f, 255.f));
	return ((r << 16) | (g << 8) | b);
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
	ray.dir = add(ray.dir, scale(right, \
		((float)x * 2.f - scene->width) / scene->width));
	ray.dir = add(ray.dir, scale(up, \
		((float)y * -2.f + scene->height) / scene->width));
	ray.dir = normalized(ray.dir);
	return (ray);
}

float	cast_ray(t_ray ray, t_objects *obj)
{
	if (obj->obj_type == (t_type)sphere)
		return (sphere_intersection(ray, *(t_sphere *)obj->obj));
	if (obj->obj_type == (t_type)plane)
		return (plane_intersection(ray, *(t_plane *)obj->obj));
	if (obj->obj_type == (t_type)cylinder)
		return (cylinder_intersection(ray, *(t_cylinder *)obj->obj));
	return (-1.f);
}
t_vec3	find_normal(t_objects *obj, t_vec3 hit_pos)
{
	if (!obj)
		return ((t_vec3){1.f, 0.f, 0.f});
	if (obj->obj_type == (t_type)sphere)
		return (sphere_normal(*(t_sphere *)obj->obj, hit_pos));
	if (obj->obj_type == (t_type)plane)
		return (plane_normal(*(t_plane *)obj->obj, hit_pos));
	if (obj->obj_type == (t_type)cylinder)
		return (cylinder_normal(*(t_cylinder *)obj->obj, hit_pos));
	return ((t_vec3){1.f, 0.f, 0.f});
}

t_hitpoint	get_hitpoint(t_scene scene, t_ray ray)
{
	t_hitpoint	hit;
	float		d;
	int			i;

	i = -1;
	hit.obj = NULL;
	hit.d = -1.f;
	while (++i < scene->nb_objects)
	{
		d = cast_ray(ray, scene->objects + i);
		if ((d > 0.f) && ((d < hit.d) || (hit.d == -1.f)))
		{
			hit.d = d;
			hit.obj = scene->objects + i;
			hit.hitpos = move_ray(ray, d);
		}
	}
	hit.normal_vect = find_normal(hit.obj, hit.hitpos);
	if (dot(hit.normal_vect, ray.dir) > 0)
		hit.normal_vect = sub((t_vec3){0.f, 0.f, 0.f}, hit.normal_vect);
	return (hit);
}

t_vec3	diffuse_light(t_scene scene, t_hitpoint hit)
{
	t_vec3		to_light;

	to_light = normalized(sub(scene->light.pos, hit.hitpos));
	return scale(hit.obj->color, fmaxf(0.f, dot(to_light, hit.normal_vect)));
}

int	in_light(t_scene scene, t_hitpoint hit)
{
	t_vec3		to_light;
	float		dist_to_light;
	t_ray		ray;
	t_hitpoint	new_hit;

	to_light = sub(scene->light.pos, hit.hitpos);
	dist_to_light = mag(to_light);
	to_light = scale(to_light, 1.f / dist_to_light);
	ray.origin = add(hit.hitpos, scale(hit.normal_vect, EPSILON));
	ray.dir = to_light;
	new_hit = get_hitpoint(scene, ray);
	if ((new_hit.d < 0.f) || (new_hit.d >= dist_to_light))
		return (1);
	return (0);
}

t_vec3	compute_pixel(t_scene scene, int x, int y)
{
	t_ray		ray;
	t_hitpoint	hit;
	t_vec3		color;

	ray = get_ray(scene, x, y);
	hit = get_hitpoint(scene, ray);
	if ((hit.d == -1.f) || (hit.obj == NULL))
		return ((t_vec3){0.f, 0.f, 0.f});
	color = mult(hit.obj->color, scene->ambient_light);
	if (in_light(scene, hit))
		color = add(color, diffuse_light(scene, hit));
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
	return ;
}
