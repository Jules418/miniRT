/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 01:46:16 by jules             #+#    #+#             */
/*   Updated: 2024/06/03 13:54:13 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include <math.h>

t_vec3	rotate_x(t_vec3 v, float angle)
{
	t_vec3	res;

	res.x = v.x;
	res.y = v.y * cosf(angle) - v.z * sinf(angle);
	res.z = v.y * sinf(angle) + v.z * cosf(angle);
	return (res);
}

t_vec3	rotate_y(t_vec3 v, float angle)
{
	t_vec3	res;

	res.x = v.x * cosf(angle) + v.z * sinf(angle);
	res.y = v.y;
	res.z = -v.x * sinf(angle) + v.z * cosf(angle);
	return (res);
}

t_vec3	rotate_z(t_vec3 v, float angle)
{
	t_vec3	res;

	res.x = v.x * cosf(angle) - v.y * sinf(angle);
	res.y = v.x * sinf(angle) + v.y * cosf(angle);
	res.z = v.z;
	return (res);
}

t_vec3	rotate_axis(t_vec3 v, t_vec3 axis, float angle)
{
	t_vec3	v_rot;
	t_vec3	tmp;

	v_rot = scale(v, cosf(angle));
	v_rot = add(v_rot, scale(cross(axis, v), sinf(angle)));
	tmp = scale(axis, dot(axis, v) * (1.f - cosf(angle)));
	return (add(v_rot, tmp));
}
