/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:35:26 by jbanacze          #+#    #+#             */
/*   Updated: 2024/06/04 15:27:28 by jbanacze         ###   ########.fr       */
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

void	move(int key, t_dlist *cameras)
{
	if (key == XK_w)
		cameras->content->pos = add(cameras->content->pos,
				scale(cameras->content->forward, 1.f));
	if (key == XK_s)
		cameras->content->pos = sub(cameras->content->pos,
				scale(cameras->content->forward, 1.f));
	if (key == XK_a)
		cameras->content->pos = sub(cameras->content->pos,
				scale(cameras->content->right, 1.f));
	if (key == XK_d)
		cameras->content->pos = add(cameras->content->pos,
				scale(cameras->content->right, 1.f));
	if (key == XK_Control_L)
		cameras->content->pos = sub(cameras->content->pos,
				scale(cameras->content->up, 1.f));
	if (key == XK_space)
		cameras->content->pos = add(cameras->content->pos,
				scale(cameras->content->up, 1.f));
}

void	move_camera(int key, t_minirt *minirt)
{
	if (!is_movement_key(key))
		return ;
	move(key, minirt->scene->cameras);
	yaw(key, minirt->scene->cameras);
	pitch(key, minirt->scene->cameras);
	roll(key, minirt->scene->cameras);
	minirt->scene->should_render = true;
}
