/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:44:24 by jbanacze          #+#    #+#             */
/*   Updated: 2024/06/03 14:06:46 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	yaw(int key, t_minirt *minirt)
{
	if (key == XK_Left || key == XK_Right)
		minirt->scene->should_render = 1;
	else
		return ;
	if (key == XK_Left)
	{
		minirt->scene->cam.forward = rotate_axis(minirt->scene->cam.forward, \
											minirt->scene->cam.up, 0.2f);
		minirt->scene->cam.right = rotate_axis(minirt->scene->cam.right, \
											minirt->scene->cam.up, 0.2f);
	}
	if (key == XK_Right)
	{
		minirt->scene->cam.forward = rotate_axis(minirt->scene->cam.forward, \
											minirt->scene->cam.up, -0.2f);
		minirt->scene->cam.right = rotate_axis(minirt->scene->cam.right, \
											minirt->scene->cam.up, -0.2f);
	}
}

void	pitch(int key, t_minirt *minirt)
{
	if (key == XK_Up || key == XK_Down)
		minirt->scene->should_render = 1;
	else
		return ;
	if (key == XK_Up)
	{
		minirt->scene->cam.forward = rotate_axis(minirt->scene->cam.forward, \
											minirt->scene->cam.right, 0.2f);
		minirt->scene->cam.up = rotate_axis(minirt->scene->cam.up, \
											minirt->scene->cam.right, 0.2f);
	}
	if (key == XK_Down)
	{
		minirt->scene->cam.forward = rotate_axis(minirt->scene->cam.forward, \
											minirt->scene->cam.right, -0.2f);
		minirt->scene->cam.up = rotate_axis(minirt->scene->cam.up, \
											minirt->scene->cam.right, -0.2f);
	}
}

void	roll(int key, t_minirt *minirt)
{
	if (key == XK_q || key == XK_e)
		minirt->scene->should_render = 1;
	else
		return ;
	if (key == XK_q)
	{
		minirt->scene->cam.up = rotate_axis(minirt->scene->cam.up, \
										minirt->scene->cam.forward, -0.2f);
		minirt->scene->cam.right = rotate_axis(minirt->scene->cam.right, \
										minirt->scene->cam.forward, -0.2f);
	}
	if (key == XK_e)
	{
		minirt->scene->cam.up = rotate_axis(minirt->scene->cam.up, \
										minirt->scene->cam.forward, 0.2f);
		minirt->scene->cam.right = rotate_axis(minirt->scene->cam.right, \
										minirt->scene->cam.forward, 0.2f);
	}
}
