/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multicam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:58:39 by lcamerly          #+#    #+#             */
/*   Updated: 2024/06/07 10:54:14 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	multicam(int key, t_minirt *minirt)
{
	if (key == XK_o || key == XK_p)
		minirt->scene->should_render = true;
	if (key == XK_o)
	{
		if (minirt->scene->cameras->next)
			minirt->scene->cameras = minirt->scene->cameras->next;
		else
			minirt->scene->cameras = ft_dlistfirst(minirt->scene->cameras);
	}
	if (key == XK_p)
	{
		if (minirt->scene->cameras->prev)
			minirt->scene->cameras = minirt->scene->cameras->prev;
		else
			minirt->scene->cameras = ft_dlstlast(minirt->scene->cameras);
	}
}
