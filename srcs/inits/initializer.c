/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:32:22 by jules             #+#    #+#             */
/*   Updated: 2024/04/17 17:45:48 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_minirt	init_minirt(int argc, char **argv)
{
	t_minirt	minirt;

	//get the scene;
	(void) argc;
	(void) argv;
	minirt.mlx = mlx_init();
	minirt.mlx_win = mlx_new_window(minirt.mlx, 800, 600, "miniRT");
	if (!minirt.mlx_win)
		exit(EXIT_FAILURE);
	minirt.img.img = mlx_new_image(minirt.mlx, 800, 600);
	minirt.img.addr = mlx_get_data_addr(minirt.img.img, \
			&minirt.img.bits_per_pixel, \
			&minirt.img.line_length, &minirt.img.endian);
	minirt.scene = NULL;
	return (minirt);
}