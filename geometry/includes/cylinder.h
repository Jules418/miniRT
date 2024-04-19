/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:03:35 by jules             #+#    #+#             */
/*   Updated: 2024/04/15 23:12:53 by jules            ###   ########.fr       */
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

t_cylinder	create_cylinder(t_vec3 pos, t_vec3 dir, float width, float height);
float		cylinder_intersection(t_ray r, t_cylinder cy);

#endif