/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:03:35 by jules             #+#    #+#             */
/*   Updated: 2024/04/21 02:12:08 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "geometry.h"

typedef struct s_cylinder
{
	t_vec3	pos;
	t_vec3	dir;
	float	width;
	float	height;
}	t_cylinder;

/*
**@brief Create a cylinder
**@param vec3
*/
t_cylinder	create_cylinder(t_vec3 pos, t_vec3 dir, float width, float height);
float		cylinder_intersection(t_ray r, t_cylinder cy);
t_vec3		cylinder_normal(t_cylinder cy, t_vec3 hit);

#endif