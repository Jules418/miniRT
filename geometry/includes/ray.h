/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 00:24:38 by jules             #+#    #+#             */
/*   Updated: 2024/05/26 20:05:17 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vector.h"

/**
 * A ray is defined by its origin and its direction
*/
typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	dir;
}	t_ray;

/**
**@brief Return the point t units away from ray origin in ray direction
**@param t_ray 	The ray
**@param float 	Distance
*/
t_vec3	move_ray(t_ray ray, float t);

#endif