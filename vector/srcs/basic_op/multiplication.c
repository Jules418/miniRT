/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplication.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:48:46 by jules             #+#    #+#             */
/*   Updated: 2024/03/20 23:56:32 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3	scale(t_vec3 v, float x)
{
	t_vec3	res;

	res.x = v.x * x;
	res.y = v.y * x;
	res.z = v.z * x;
	return (res);
}

t_vec3	mult(t_vec3 u, t_vec3 v)
{
	t_vec3	res;

	res.x = u.x * v.x;
	res.y = u.y * v.y;
	res.z = u.z * v.z;
	return (res);
}

float	dot(t_vec3 u, t_vec3 v)
{
	t_vec3	tmp;

	tmp = mult(u, v);
	return (tmp.x + tmp.y + tmp.z);
}

t_vec3	cross(t_vec3 u, t_vec3 v)
{
	t_vec3	res;

	res.x = u.y * v.z - u.z * v.y;
	res.y = u.z * v.x - u.x * v.z;
	res.z = u.x * v.y - u.y * v.x;
	return (res);
}
