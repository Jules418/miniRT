/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:03:35 by jules             #+#    #+#             */
/*   Updated: 2024/04/24 11:17:02 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "geometry.h"

/**
* A cylinder is defined by its center, its direction, its height and width
*/
typedef struct s_cylinder
{
	t_vec3	pos;
	t_vec3	dir;
	float	width;
	float	height;
}	t_cylinder;

/**
**@brief Create a cylinder
**@param t_vec3 The position of the cylinder's center
**@param t_vec3 The direction in wich the cylinder is pointing
**@param float 	Distance between pos and the sides
**@param float Distance between the 2 caps
*/
t_cylinder	create_cylinder(t_vec3 pos, t_vec3 dir, float width, float height);

/**
**@brief Return the first intersection between a ray and a cylinder
**@param t_ray 		The ray you want to intersect the cylinder with
**@param t_cylinder The cylinder you want to intersect the ray with
*
* Source : 
*	https://mrl.cs.nyu.edu/~dzorin/rendering/lectures/lecture3/lecture3.pdf
*/
float		cylinder_intersection(t_ray r, t_cylinder cy);

/**
**@brief Return the normal vector in a point on the surface of the cylinder
**@param t_cylinder The cylinder
**@param t_vec3 	A point on the cylinder's surface
*/
t_vec3		cylinder_normal(t_cylinder cy, t_vec3 hit);

#endif