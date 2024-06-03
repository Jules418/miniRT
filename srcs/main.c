/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:54:08 by jules             #+#    #+#             */
/*   Updated: 2024/06/03 10:53:16 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	draw_loop(t_minirt *minirt)
{
	if (render_scene(minirt))
		close_minirt(minirt);
	mlx_put_image_to_window(minirt->mlx, minirt->mlx_win, minirt->img.img, 0, \
		0);
	return (0);
}

int	input(int key, t_minirt *minirt)
{
	if (key == XK_Escape)
		close_minirt(minirt);
	if (key == XK_z)
		minirt->scene->cam.pos = add(minirt->scene->cam.pos, \
		scale(minirt->scene->cam.forward, 10.f));
	if (key == XK_s)
		minirt->scene->cam.pos = sub(minirt->scene->cam.pos, \
		scale(minirt->scene->cam.forward, 10.f));
	if (key == XK_q)
		minirt->scene->cam.pos = sub(minirt->scene->cam.pos, \
		scale(minirt->scene->cam.right, 10.f));
	if (key == XK_d)
		minirt->scene->cam.pos = add(minirt->scene->cam.pos, \
		scale(minirt->scene->cam.right, 10.f));
	if (key == XK_Control_L)
		minirt->scene->cam.pos = sub(minirt->scene->cam.pos, \
		scale(minirt->scene->cam.up, 10.f));
	if (key == XK_space)
		minirt->scene->cam.pos = add(minirt->scene->cam.pos, \
		scale(minirt->scene->cam.up, 10.f));
	minirt->scene->should_render = 1;
	return (0);
}

int	main(int argc, char **argv)
{
	t_minirt	minirt;
	char		**map;

	map = NULL;
	if (argc == 2)
	{
		map = parsing(argv);
		init_scene(map, &minirt);
		init_minirt(&minirt);
		if (!minirt.scene)
		{
			close_minirt(&minirt);
			return (1);
		}
		mlx_hook(minirt.mlx_win, 17, 1L << 0, close_minirt, &minirt);
		mlx_hook(minirt.mlx_win, DestroyNotify, StructureNotifyMask, \
			close_minirt, &minirt);
		mlx_hook(minirt.mlx_win, KeyPress, KeyPressMask, input, &minirt);
		mlx_loop_hook(minirt.mlx, draw_loop, &minirt);
		mlx_loop(minirt.mlx);
	}
	return (0);
}
