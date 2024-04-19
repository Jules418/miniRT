/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:54:08 by jules             #+#    #+#             */
/*   Updated: 2024/04/18 21:56:24 by jbanacze         ###   ########.fr       */
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

void	free_scene(t_scene scene)
{
	int	i;

	if (!scene)
		return ;
	i = 0;
	while (i < scene->nb_objects)
	{
		free(scene->objects[i].obj);
		i++;
	}
	free(scene);
}

int	close_minirt(t_minirt *minirt)
{
	mlx_destroy_image(minirt->mlx, minirt->img.img);
	mlx_destroy_window(minirt->mlx, minirt->mlx_win);
	mlx_destroy_display(minirt->mlx);
	free(minirt->mlx);
	free_scene(minirt->scene);
	exit(EXIT_SUCCESS);
	return (0);
}

int	draw_loop(t_minirt *minirt)
{
	render_scene(minirt);
	mlx_put_image_to_window(minirt->mlx, minirt->mlx_win, minirt->img.img, 0 ,0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_minirt	minirt;

	minirt = init_minirt(argc, argv);
	minirt.scene = test_scene();
	mlx_hook(minirt.mlx_win, 17, 1L << 0, close_minirt, &minirt);
	mlx_loop_hook(minirt.mlx, draw_loop, &minirt);
	mlx_loop(minirt.mlx);
	return (0);
}
