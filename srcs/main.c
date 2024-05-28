/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:54:08 by jules             #+#    #+#             */
/*   Updated: 2024/05/28 16:29:09 by lcamerly         ###   ########.fr       */
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

int	input(int key, t_minirt *minirt)
{
	if (key == XK_Escape)
		close_minirt(minirt);
	return (0);
}

int	draw_loop(t_minirt *minirt)
{
	render_scene(minirt);
	mlx_put_image_to_window(minirt->mlx, minirt->mlx_win, minirt->img.img, 0, \
		0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_minirt	minirt;

	char **tmp = NULL;

	if (argc == 2)
	{
		tmp = parsing(argv);
		for (int i = 0; tmp[i]; ++i) {
			printf("%s" ,tmp[i]);
			printf("\n");
		}
	}
	minirt = init_minirt(argc, argv);
	minirt.scene = test_scene();
	check_ambientlight(tmp[0]) ,init_ambiantlight(tmp[0], &minirt);
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
	return (0);
}