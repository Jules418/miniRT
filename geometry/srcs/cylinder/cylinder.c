/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:07:37 by jules             #+#    #+#             */
/*   Updated: 2024/04/19 05:47:10 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"


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
	(void) cy;
	(void) hit;
	return ((t_vec3){0.f, 0.f, 0.f});
}