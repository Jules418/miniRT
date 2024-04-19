/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:34:16 by jules             #+#    #+#             */
/*   Updated: 2024/04/15 22:05:07 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

t_vec3	add(t_vec3 u, t_vec3 v);
t_vec3	sub(t_vec3 u, t_vec3 v);
t_vec3	scale(t_vec3 v, float x);
t_vec3	mult(t_vec3 u, t_vec3 v);
float	dot(t_vec3 u, t_vec3 v);
t_vec3	cross(t_vec3 u, t_vec3 v);

float	mag2(t_vec3 v);
float	mag(t_vec3 v);
t_vec3	normalized(t_vec3 v);
t_vec3	normalize(t_vec3 *v);

t_vec3	q_normalized(t_vec3 v);
t_vec3	q_normalize(t_vec3 *v);

t_vec3	rotate_x(t_vec3 v, float angle);
t_vec3	rotate_y(t_vec3 v, float angle);
t_vec3	rotate_z(t_vec3 v, float angle);

#endif