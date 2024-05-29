/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:13:05 by jules             #+#    #+#             */
/*   Updated: 2024/05/29 01:39:41 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "geometry.h"

/**
* A plane is defined by its normal vector 
*	(vector of lenght perpendicular to the plane)
* and a single point the plane pass through
*
*/
typedef struct s_plane
{
	t_vec3	pos;
	t_vec3	normal_vector;
}	t_plane;

/**
**@brief Create a plane
**@param t_vec3 	A point in the plane
**@param t_vec3 	A normal vector of the plane
*/
t_plane	create_plane(t_vec3 pos, t_vec3 normal_vector);

/**
**@brief Return the first intersection between a ray and a plane
**@param t_ray 		The ray you want to intersect the plane with
**@param t_plane 	The plane you want to intersect the ray with
* Source :
*	https://shorturl.at/dwBO8
*/
float	plane_intersection(t_ray ray, t_plane pl);

/**
**@brief Return the normal vector of the plane
**@param t_plane 	The plane
**@param t_vec3 	A point in the plane (not used in mandatory)*/
t_vec3	plane_normal(t_plane pl, t_vec3 hit);

#endif