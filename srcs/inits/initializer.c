/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:32:22 by jules             #+#    #+#             */
/*   Updated: 2024/06/02 09:22:45 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_minirt(t_minirt *minirt)
{
	minirt->mlx = mlx_init();
	minirt->mlx_win = mlx_new_window(minirt->mlx, TEMP_WIDTH, TEMP_HEIGHT,
			"miniRT");
	if (!minirt->mlx_win)
		exit_error("Error in the mlx allocation\n");
	minirt->img.img = mlx_new_image(minirt->mlx, TEMP_WIDTH, TEMP_HEIGHT);
	minirt->img.addr = mlx_get_data_addr(minirt->img.img,
			&minirt->img.bits_per_pixel, &minirt->img.line_length,
			&minirt->img.endian);
}

void	free_light(t_list *light)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = light;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp->content);
		free(tmp);
		tmp = tmp2;
	}
}

void	free_scene(t_scene scene)
{
	t_list		*tmp;
	t_list		*tmp2;
	t_objects	*tmp_obj;

	tmp = scene->objects;
	free_light(scene->lights);
	while (tmp)
	{
		tmp2 = tmp->next;
		tmp_obj = tmp->content;
		if (tmp_obj->obj_type == (t_type)sphere)
			free(tmp_obj->obj);
		else if (tmp_obj->obj_type == (t_type)plane)
			free(tmp_obj->obj);
		else if (tmp_obj->obj_type == (t_type)cylinder)
			free(tmp_obj->obj);
		else if (tmp_obj->obj_type == (t_type)cone)
			free(tmp_obj->obj);
		free(tmp->content);
		free(tmp);
		tmp = tmp2;
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
	free_exit(0);
	return (0);
}
