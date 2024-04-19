/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:14:34 by jules             #+#    #+#             */
/*   Updated: 2024/04/16 11:02:56 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include <math.h>

t_plane	create_plane(t_vec3 pos, t_vec3 normal_vector)
{
	t_plane	pl;

	pl.pos = pos;
	pl.normal_vector = normal_vector;
	return (pl);
}

float	plane_intersection(t_ray ray, t_plane pl)
{
	float	denom;
	t_vec3	oc;
	float	t;

	denom = fabsf(dot(pl.normal_vector, ray.dir));
	if (denom < EPSILON)
		return (-1.f);
	oc = sub(pl.pos, ray.origin);
	t = dot(oc, pl.normal_vector) / denom;
	if (t < 0.f)
		return (-1.f);
	return (t);
}
