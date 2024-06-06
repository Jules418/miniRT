/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:09:59 by jbanacze          #+#    #+#             */
/*   Updated: 2024/06/06 10:24:24 by lcamerly         ###   ########.fr       */
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
		{
			color = add(color, diffuse_light(hit, light->content));
			color = add(color, specular_light(ray, hit, light->content));
		}
		light = light->next;
	}
	return (color);
}

void	*render_partial_scene(void *arg)
{
	t_threadarg	*args;
	t_scene		scene;
	int			x;
	int			y;
	int			color;

	args = (t_threadarg *) arg;
	scene = args->minirt->scene;
	y = args->start;
	while (y < args->end)
	{
		x = 0;
		while (x < scene->width)
		{
			color = vec_to_rgb(compute_pixel(scene, x, y));
			my_mlx_pixel_put(&args->minirt->img, x, y, color);
			x++;
		}
		y++;
	}
	return (NULL);
}

void	init_thread_args(t_minirt *minirt, t_threadarg args[NB_THREADS])
{
	int	i;
	int	step;
	int	current_height;

	i = 0;
	current_height = 0;
	step = minirt->scene->height / NB_THREADS;
	while (i < NB_THREADS - 1)
	{
		args[i].start = current_height;
		args[i].end = current_height + step;
		current_height += step;
		args[i].minirt = minirt;
		i++;
	}
	args[i].start = current_height;
	args[i].end = minirt->scene->height;
	args[i].minirt = minirt;
}

int	render_scene(t_minirt *minirt)
{
	t_scene		scene;
	t_threadarg	args[NB_THREADS];
	pthread_t	threads[NB_THREADS];
	int			i;
	int			error;

	error = 0;
	scene = minirt->scene;
	if (!scene || !(scene->should_render))
		return (error);
	scene->should_render = 0;
	init_thread_args(minirt, args);
	i = -1;
	while (++i < NB_THREADS)
	{
		if (pthread_create(threads + i, NULL, render_partial_scene, args + i))
		{
			perror("Error during the creation of a thread");
			error = 1;
			break ;
		}
	}
	while (--i >= 0)
		pthread_join(threads[i], NULL);
	return (error);
}
