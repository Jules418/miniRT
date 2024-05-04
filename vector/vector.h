/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:34:16 by jules             #+#    #+#             */
/*   Updated: 2024/05/04 11:47:05 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

/**
 * A vec3 has 3 components, x, y and z
 * 	It can represent a vector, anything that is represented with 3 numbers
 * 	(vector, position, colors, ...)
*/
typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

/**
 * @brief Return the sum of 2 vectors u and v
 * @param t_vec3 u
 * @param t_vec3 v
*/
t_vec3	add(t_vec3 u, t_vec3 v);

/**
 * @brief Return the difference of 2 vectors u and v
 * @param t_vec3 u
 * @param t_vec3 v
 * 
 * 	If u and v are points in space, v - u gives the vector UV (from u to v)
*/
t_vec3	sub(t_vec3 u, t_vec3 v);

/**
 * @brief Return a vector u scaled by the factor x
 * @param t_vec3 u
 * @param t_vec3 scale factor x
 * 
 * || u*x = Vec3(u.x * x, u.y * x, u.z * x)
*/
t_vec3	scale(t_vec3 v, float x);

/**
 * @brief Return the "multiplication" of 2 vectors component per component
 * @param t_vec3 u
 * @param t_vec3 v
*/
t_vec3	mult(t_vec3 u, t_vec3 v);

/**
 * @brief Return the dot product of u and v (u.x * v.x + u.y * v.y + u.z * v.z)
 * @param t_vec3 u
 * @param t_vec3 v
*/
float	dot(t_vec3 u, t_vec3 v);

/**
 * @brief Return the cross product of u and v (vector perpendicular to u and v)
 * @param t_vec3 u
 * @param t_vec3 v
*/
t_vec3	cross(t_vec3 u, t_vec3 v);

/**
 * @brief Return the length of v squared
 * @param t_vec3 v
*/
float	mag2(t_vec3 v);

/**
 * @brief Return the length of v
 * @param t_vec3 v
*/
float	mag(t_vec3 v);

/**
 * @brief Return v normalized (same direction as v, but length 1)
 * @param t_vec3 v
*/
t_vec3	normalized(t_vec3 v);

/**
 * @brief Normalize v and return it
 * @param t_vec3* v
*/
t_vec3	normalize(t_vec3 *v);

/**
 * @brief Same as normalized(v), but faster and a bit imprecise
 * @param t_vec3 v
*/
t_vec3	q_normalized(t_vec3 v);

/**
 * @brief Same as normalize(v), but faster and a bit imprecise
 * @param t_vec3* v
*/
t_vec3	q_normalize(t_vec3 *v);

t_vec3	reflect(t_vec3 u, t_vec3 n);

t_vec3	rotate_x(t_vec3 v, float angle);
t_vec3	rotate_y(t_vec3 v, float angle);
t_vec3	rotate_z(t_vec3 v, float angle);

#endif