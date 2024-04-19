/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:07:37 by jules             #+#    #+#             */
/*   Updated: 2024/04/16 15:26:21 by jules            ###   ########.fr       */
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
