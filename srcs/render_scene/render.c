/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:09:59 by jbanacze          #+#    #+#             */
/*   Updated: 2024/05/04 11:57:47 by jules            ###   ########.fr       */
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
	{
		color = add(color, diffuse_light(scene, hit));
		color = add(color, specular_light(scene, ray, hit));
	}
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
