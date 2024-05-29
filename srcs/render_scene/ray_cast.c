/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 02:23:51 by jules             #+#    #+#             */
/*   Updated: 2024/05/29 03:12:40 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

float	cast_ray(t_ray ray, t_objects *obj)
{
	if (obj->obj_type == (t_type)sphere)
		return (sphere_intersection(ray, *(t_sphere *)obj->obj));
	if (obj->obj_type == (t_type)plane)
		return (plane_intersection(ray, *(t_plane *)obj->obj));
	if (obj->obj_type == (t_type)cylinder)
		return (cylinder_intersection(ray, *(t_cylinder *)obj->obj));
	if (obj->obj_type == (t_type)cone)
		return (cone_intersection(ray, *(t_cone *)obj->obj));
	return (-1.f);
}

t_hitpoint	get_hitpoint(t_scene scene, t_ray ray)
{
	t_hitpoint	hit;
	float		d;
	int			i;

	i = -1;
	hit.obj = NULL;
	hit.d = -1.f;
	while (++i < scene->nb_objects)
	{
		d = cast_ray(ray, scene->objects + i);
		if ((d > 0.f) && ((d < hit.d) || (hit.d == -1.f)))
		{
			hit.d = d;
			hit.obj = scene->objects + i;
			hit.hitpos = move_ray(ray, d);
		}
	}
	hit.normal_vect = find_normal(hit.obj, hit.hitpos);
	if (dot(hit.normal_vect, ray.dir) > 0)
		hit.normal_vect = sub((t_vec3){0.f, 0.f, 0.f}, hit.normal_vect);
	return (hit);
}
