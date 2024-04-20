/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:32:22 by jules             #+#    #+#             */
/*   Updated: 2024/04/20 17:08:30 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//get the scene;
t_minirt	init_minirt(int argc, char **argv)
{
	t_minirt	minirt;

	(void) argc;
	(void) argv;
	minirt.mlx = mlx_init();
	minirt.mlx_win = mlx_new_window(minirt.mlx, TEMP_WIDTH, TEMP_HEIGHT, "miniRT");
	if (!minirt.mlx_win)
		exit(EXIT_FAILURE);
	minirt.img.img = mlx_new_image(minirt.mlx, TEMP_WIDTH, TEMP_HEIGHT);
	minirt.img.addr = mlx_get_data_addr(minirt.img.img, \
			&minirt.img.bits_per_pixel, \
			&minirt.img.line_length, &minirt.img.endian);
	minirt.scene = NULL;
	return (minirt);
}
