/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:11:48 by jules             #+#    #+#             */
/*   Updated: 2024/04/24 11:50:52 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "geometry.h"

/**
 * A sphere is defined by its position and it radius
*/
typedef struct s_sphere
{
	t_vec3	pos;
	float	radius;
}	t_sphere;

/**
 * @brief Create a sphere
 * @param t_vec3 Position
 * @param float Radius
*/
t_sphere	create_sphere(t_vec3 pos, float radius);

/**
 * @brief Return the first intersection between a ray and a sphere
 * @param t_ray The ray you want to intersect the sphere with
 * @param t_sphere The sphere you want to intersect the ray with
 * 
 * Source :
 * 	https://shorturl.at/QRXY5
*/
float		sphere_intersection(t_ray r, t_sphere sp);

/**
 * @brief Return the normal vector in a point on the surface of the sphere
 * @param t_sphere The sphere
 * @param t_vec3 A point on the sphere's surface
*/
t_vec3		sphere_normal(t_sphere s, t_vec3 hit);

#endif