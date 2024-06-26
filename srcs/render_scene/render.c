/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:09:59 by jbanacze          #+#    #+#             */
/*   Updated: 2024/06/07 10:47:18 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	get_ray(t_scene scene, int x, int y)
{
	t_ray	ray;
	t_vec3	forward;
	t_vec3	up;
	t_vec3	right;

	forward = scene->cameras->content->forward;
	up = scene->cameras->content->up;
	right = scene->cameras->content->right;
	ray.origin = scene->cameras->content->pos;
	ray.dir = scale(forward, scene->cameras->content->d_to_screen);
	ray.dir = add(ray.dir, scale(right, ((float)x * 2.f - scene->width)
				/ scene->width));
	ray.dir = add(ray.dir, scale(up, ((float)y * -2.f + scene->height)
				/ scene->width));
	ray.dir = normalized(ray.dir);
	return (ray);
}

t_vec3	compute_pixel(t_scene scene, int x, int y)
{
	t_ray		ray;
	t_hitpoint	hit;
	t_vec3		color;
	t_list		*light;

	ray = get_ray(scene, x, y);
	hit = get_hitpoint(scene, ray);
	if ((hit.d == -1.f) || (hit.obj == NULL))
		return ((t_vec3){0.f, 0.f, 0.f});
	color = mult(hit.obj->color, scene->ambient_light);
	light = scene->lights;
	while (light)
	{
		if (in_light(scene, hit, light->content))
			color = add(color, diffuse_light(hit, light->content));
		light = light->next;
	}
	return (color);
}

void	render_scene(t_minirt *minirt)
{
	t_scene		scene;
	int			x;
	int			y;
	int			color;

	scene = minirt->scene;
	if (!scene || !(scene->should_render))
		return ;
	scene->should_render = 0;
	y = 0;
	while (y < scene->height)
	{
		x = 0;
		while (x < scene->width)
		{
			color = vec_to_rgb(compute_pixel(scene, x, y));
			my_mlx_pixel_put(&minirt->img, x, y, color);
			x++;
		}
		y++;
	}
}
