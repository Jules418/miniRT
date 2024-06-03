/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:44:24 by jbanacze          #+#    #+#             */
/*   Updated: 2024/06/03 17:21:33 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	yaw(int key, t_dlist *cameras)
{
	if (key == XK_Left)
	{
		cameras->content->forward = rotate_axis(cameras->content->forward,
				cameras->content->up, 0.2f);
		cameras->content->right = rotate_axis(cameras->content->right,
				cameras->content->up, 0.2f);
	}
	if (key == XK_Right)
	{
		cameras->content->forward = rotate_axis(cameras->content->forward,
				cameras->content->up, -0.2f);
		cameras->content->right = rotate_axis(cameras->content->right,
				cameras->content->up, -0.2f);
	}
}

void	pitch(int key, t_dlist *cameras)
{
	if (key == XK_Up)
	{
		cameras->content->forward = rotate_axis(cameras->content->forward,
				cameras->content->right, 0.2f);
		cameras->content->up = rotate_axis(cameras->content->up,
				cameras->content->right, 0.2f);
	}
	if (key == XK_Down)
	{
		cameras->content->forward = rotate_axis(cameras->content->forward,
				cameras->content->right, -0.2f);
		cameras->content->up = rotate_axis(cameras->content->up,
				cameras->content->right, -0.2f);
	}
}

void	roll(int key, t_dlist *cameras)
{
	if (key == XK_q)
	{
		cameras->content->up = rotate_axis(cameras->content->up,
				cameras->content->forward, -0.2f);
		cameras->content->right = rotate_axis(cameras->content->right,
				cameras->content->forward, -0.2f);
	}
	if (key == XK_e)
	{
		cameras->content->up = rotate_axis(cameras->content->up,
				cameras->content->forward, 0.2f);
		cameras->content->right = rotate_axis(cameras->content->right,
				cameras->content->forward, 0.2f);
	}
}
