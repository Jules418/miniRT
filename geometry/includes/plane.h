/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:13:05 by jules             #+#    #+#             */
/*   Updated: 2024/04/19 05:34:45 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "geometry.h"

typedef struct s_plane
{
	t_vec3	pos;
	t_vec3	normal_vector;
}	t_plane;

t_plane	create_plane(t_vec3 pos, t_vec3 normal_vector);
float	plane_intersection(t_ray ray, t_plane pl);
t_vec3	plane_normal(t_plane pl, t_vec3 hit);

#endif