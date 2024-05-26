/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:32:22 by jules             #+#    #+#             */
/*   Updated: 2024/05/26 20:31:57 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//get the scene;
t_minirt	init_minirt(int argc, char **argv)
{
	t_minirt	minirt;

	(void)(argc + argv);
	minirt.mlx = mlx_init();
	minirt.mlx_win = mlx_new_window(minirt.mlx, TEMP_WIDTH, \
		TEMP_HEIGHT, "miniRT");
	if (!minirt.mlx_win)
		exit(EXIT_FAILURE);
	minirt.img.img = mlx_new_image(minirt.mlx, TEMP_WIDTH, TEMP_HEIGHT);
	minirt.img.addr = mlx_get_data_addr(minirt.img.img, \
			&minirt.img.bits_per_pixel, \
			&minirt.img.line_length, &minirt.img.endian);
	minirt.scene = NULL;
	return (minirt);
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
