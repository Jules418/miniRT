/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_norm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 00:05:57 by jules             #+#    #+#             */
/*   Updated: 2024/03/21 01:42:07 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "conv.h"

float	q_rsqrt(float number)
{
	t_conv	conv;

	conv = (t_conv){.f = number};
	conv.i = 0x5f3759df - (conv.i >> 1);
	conv.f *= 1.5F - (number * 0.5F * conv.f * conv.f);
	return (conv.f);
}

// float	q_rsqrt(float number)
// {
// 	long		i;
// 	float		x2;
// 	float		y;
// 	const float	threehalfs = 1.5f;

// 	x2 = number * 0.5F;
// 	y = number;
// 	i = *(long *)(&y);
// 	i = 0x5f3759df - (i >> 1);
// 	y = *(float *)(&i);
// 	y = y * (threehalfs - (x2 * y * y));
// 	return (y);
// }

t_vec3	q_normalized(t_vec3 v)
{
	float	q_rnorm;

	q_rnorm = q_rsqrt(dot(v, v));
	return (scale(v, q_rnorm));
}

t_vec3	q_normalize(t_vec3 *v)
{
	t_vec3	tmp;

	tmp = q_normalized(*v);
	*v = tmp;
	return (tmp);
}
