/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:25:59 by jules             #+#    #+#             */
/*   Updated: 2024/04/19 03:10:18 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "utils.h"
#include <math.h>

float	caps_intersection(t_ray ray, t_cylinder cy)
{
	t_plane	p1;
	t_plane	p2;
	float	t1;
	float	t2;

	p1 = create_plane(add(cy.pos, scale(cy.dir, cy.height / 2.f)), cy.dir);
	t1 = plane_intersection(ray, p1);
	if (t1 > 0.f)
		if (mag2(sub(move_ray(ray, t1), p1.pos)) > (cy.width * cy.width))
			t1 = -1.f;
	p2 = create_plane(sub(cy.pos, scale(cy.dir, cy.height / 2.f)), cy.dir);
	t2 = plane_intersection(ray, p2);
	if (t2 > 0.f)
		if (mag2(sub(move_ray(ray, t2), p2.pos)) > (cy.width * cy.width))
			t2 = -1.f;
	if (t1 < 0.f)
		return (t2);
	if (t2 < 0.f)
		return (t1);
	return (fminf(t1, t2));
}

t_vec3	inter_op(t_vec3 v, t_vec3 va)
{
	return (sub(v, scale(va, dot(v, va))));
}

float	filter_hit_points(t_ray ray, t_cylinder cy, float coefs[6])
{
	float	t;
	t_vec3	hit_point;

	t = coefs[4];
	if (t < 0.f)
	{
		hit_point = move_ray(ray, t);
		if (mag2(sub(hit_point, cy.pos)) < (cy.height * cy.height / 4.f \
				+ cy.width * cy.width))
			return (t);
	}
	t = coefs[5];
	if (t < 0.f)
	{
		hit_point = move_ray(ray, t);
		if (mag2(sub(hit_point, cy.pos)) < (cy.height * cy.height / 4.f \
				+ cy.width * cy.width))
			return (t);
	}
	return (-1.f);
}

float	sides_intersection(t_ray ray, t_cylinder cy)
{
	t_vec3	oc;
	float	coefs[6];

	oc = sub(ray.origin, cy.pos);
	coefs[0] = mag2(inter_op(ray.dir, cy.dir));
	coefs[1] = 2.f * dot(inter_op(ray.dir, cy.dir), inter_op(oc, cy.dir));
	coefs[2] = mag2(inter_op(oc, cy.dir)) - (cy.width * cy.width);
	solve_quadratic(coefs);
	if (coefs[3] < 0.f)
		return (-1.f);
	return (filter_hit_points(ray, cy, coefs));
}

float	cylinder_intersection(t_ray ray, t_cylinder cy)
{
	float	sides;
	float	caps;

	sides = sides_intersection(ray, cy);
	caps = caps_intersection(ray, cy);
	if (sides < 0.f)
		return (caps);
	if (caps < 0.f)
		return (sides);
	return (fminf(sides, caps));
}
