/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:57:40 by jules             #+#    #+#             */
/*   Updated: 2024/06/03 18:43:10 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"
#include "math.h"

t_cone	create_cone(t_vec3 pos, t_vec3 dir, float angle, float height)
{
	t_cone	co;

	co.pos = pos;
	co.dir = dir;
	co.angle = angle;
	co.cos2 = powf(cosf(angle), 2.f);
	co.height = height;
	return (co);
}

t_vec3	cone_normal(t_cone co, t_vec3 hit)
{
	t_vec3	ch;
	float	t;
	t_vec3	p;
	t_vec3	np;
	t_vec3	n;

	ch = sub(hit, co.pos);
	t = dot(ch, co.dir);
	if (t + EPSILON >= co.height)
		return (co.dir);
	p = add(co.pos, scale(co.dir, t));
	np = scale(sub(hit, p), 1.f / (tanf(co.angle) * t));
	n = sub(scale(np, cosf(co.angle)), scale(co.dir, sinf(co.angle)));
	return (n);
}
