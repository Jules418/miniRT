/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:35:26 by jbanacze          #+#    #+#             */
/*   Updated: 2024/06/03 14:00:42 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	is_movement_key(int key)
{
	if (key == XK_w || key == XK_s || key == XK_a || key == XK_d)
		return (true);
	if (key == XK_Control_L || key == XK_space)
		return (true);
	if (key == XK_Left || key == XK_Right || key == XK_Up || key == XK_Down)
		return (true);
	if (key == XK_q || key == XK_e)
		return (true);
	return (false);
}

void	move(int key, t_minirt *minirt)
{
	if (key == XK_w || key == XK_s || key == XK_a || key == XK_d || \
		key == XK_Control_L || key == XK_space)
		minirt->scene->should_render = 1;
	if (key == XK_w)
		minirt->scene->cam.pos = add(minirt->scene->cam.pos, \
		scale(minirt->scene->cam.forward, 10.f));
	if (key == XK_s)
		minirt->scene->cam.pos = sub(minirt->scene->cam.pos, \
		scale(minirt->scene->cam.forward, 10.f));
	if (key == XK_a)
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
}

void	move_camera(int key, t_minirt *minirt)
{
	if (!is_movement_key(key))
		return ;
	move(key, minirt);
	yaw(key, minirt);
	pitch(key, minirt);
	roll(key, minirt);
}
