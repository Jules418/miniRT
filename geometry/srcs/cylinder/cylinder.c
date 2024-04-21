/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:07:37 by jules             #+#    #+#             */
/*   Updated: 2024/04/21 02:11:11 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include <math.h>

t_cylinder	create_cylinder(t_vec3 pos, t_vec3 dir, float width, float height)
{
	t_cylinder	cy;

	cy.pos = pos;
	cy.dir = dir;
	cy.width = width;
	cy.height = height;
	return (cy);
}

t_vec3	cylinder_normal(t_cylinder cy, t_vec3 hit)
{
	t_vec3	op;
	float	t;

	op = sub(hit, cy.pos);
	t = dot(op, cy.dir);
	if (fabsf(t - cy.height / 2.f) < EPSILON)
		return (cy.dir);
	if (fabsf(t + cy.height / 2.f) < EPSILON)
		return (cy.dir);
	op = add(cy.pos, scale(cy.dir, t));
	return (scale(sub(hit, op), 1.f / cy.width));
}
