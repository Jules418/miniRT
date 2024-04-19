/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:14:49 by jules             #+#    #+#             */
/*   Updated: 2024/04/19 03:25:41 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include <math.h>
#include <stdio.h>

t_sphere	create_sphere(t_vec3 pos, float radius)
{
	t_sphere	sp;

	sp.pos = pos;
	sp.radius = radius;
	return (sp);
}

float	sphere_intersection(t_ray ray, t_sphere sp)
{
	t_vec3	oc;
	float	t;
	float	b;
	float	c;
	float	delta;

	oc = sub(ray.origin, sp.pos);
	b = 2.0 * dot(oc, ray.dir);
	c = mag2(oc) - (sp.radius * sp.radius);
	delta = (b * b) - (4 * c);
	if (delta < 0)
		return (-1.f);
	if (delta < EPSILON)
		t = -b / 2.0f;
	else
		t = ((-b - sqrtf(delta)) / 2.0f);
	if (t > 0.f)
		return (t);
	t = ((-b + sqrtf(delta)) / 2.0f);
	if (t > 0.f)
		return (t);
	return (-1.f);
}

t_vec3	normal_sphere(t_sphere s, t_vec3 hit)
{
	t_vec3	normal_vec;

	normal_vec = sub(hit, s.pos);
	return (normalized(normal_vec));
}