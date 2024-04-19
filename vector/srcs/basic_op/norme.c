/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:57:46 by jules             #+#    #+#             */
/*   Updated: 2024/03/21 00:13:58 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

float	mag2(t_vec3 v)
{
	return (dot(v, v));
}

float	mag(t_vec3 v)
{
	return (sqrtf(mag2(v)));
}

t_vec3	normalized(t_vec3 v)
{
	float	norm;

	norm = mag(v);
	return (scale(v, 1. / norm));
}

t_vec3	normalize(t_vec3 *v)
{
	t_vec3	tmp;

	tmp = normalized(*v);
	*v = tmp;
	return (tmp);
}
