/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:42:58 by jules             #+#    #+#             */
/*   Updated: 2024/05/11 23:49:18 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"
#include "utils.h"
#include "math.h"

float	filter_side_hits(t_ray ray, t_cone co, float coefs[6])
{
	float	t;
	t_vec3	hit_pos;
	t_vec3	ch;
	float	t1;
	float	t2;

	t1 = -1.f;
	t2 = -1.f;
	if (coefs[5] > 0.f)
	{
		hit_pos = move_ray(ray, coefs[5]);
		ch = sub(hit_pos, co.pos);
		t = dot(ch, co.dir);
		if ((t > 0.f) && (t < co.height))
			t1 = coefs[5];
	}
	if (coefs[4] > 0.f)
	{
		hit_pos = move_ray(ray, coefs[4]);
		ch = sub(hit_pos, co.pos);
		t = dot(ch, co.dir);
		if ((t > 0.f) && (t < co.height))
			t2 = coefs[4];
	}
	return (min_cast(t1, t2));
}

float	cone_side_intersection(t_ray ray, t_cone co)
{
	float	coefs[6];
	t_vec3	oc;

	oc = sub(ray.origin, co.pos);
	coefs[0] = powf(dot(ray.dir, co.dir), 2.f) - co.cos2;
	coefs[1] = dot(ray.dir, co.dir) * dot(oc, co.dir) - \
			dot(ray.dir, scale(oc, co.cos2));
	coefs[1] *= 2.f;
	coefs[2] = powf(dot(oc, co.dir), 2.f) - mag2(oc) * co.cos2;
	solve_quadratic(coefs);
	if (coefs[3] < EPSILON)
		return (-1.f);
	return (filter_side_hits(ray, co, coefs));
}

float	cone_bottom_intersection(t_ray ray, t_cone co)
{
	t_plane pl;
	float	t;
	t_vec3	hit_pos;

	pl = create_plane(add(co.pos, scale(co.dir, co.height)), co.dir);
	t = plane_intersection(ray, pl);
	if (t < 0.f)
		return (-1.f);
	hit_pos = move_ray(ray, t);
	if (mag2(sub(hit_pos, pl.pos)) <= powf(tanf(co.angle) * co.height, 2.f))
		return (t);
	return (-1.f);
}

float	cone_intersection(t_ray ray, t_cone co)
{
	float	sides;
	float	bottom;

	sides = cone_side_intersection(ray, co);
	bottom = cone_bottom_intersection(ray, co);
	return (min_cast(sides, bottom));
}