/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:22:18 by jules             #+#    #+#             */
/*   Updated: 2024/05/12 00:11:09 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONE_H
# define CONE_H

# include "geometry.h"

typedef struct s_cone
{
	t_vec3	pos;
	t_vec3	dir;
	float	angle;
	float	cos2;
	float	height;
}	t_cone;

t_cone	create_cone(t_vec3 pos, t_vec3 dir, float angle, float height);
float	cone_intersection(t_ray ray, t_cone co);
t_vec3	cone_normal(t_cone co, t_vec3 hit);

#endif