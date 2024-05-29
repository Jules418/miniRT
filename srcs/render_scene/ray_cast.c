/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 02:23:51 by jules             #+#    #+#             */
/*   Updated: 2024/05/29 17:35:52 by jules            ###   ########.fr       */
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
	t_list		*tmp;

	hit.obj = NULL;
	hit.d = -1.f;
	tmp = scene->objects;
	while (tmp)
	{
		d = cast_ray(ray, tmp->content);
		if (d > 0 && (d < hit.d || hit.d < 0))
		{
			hit.d = d;
			hit.obj = tmp->content;
			hit.hitpos = move_ray(ray, d);
		}
		tmp = tmp->next;
	}
	hit.normal_vect = find_normal(hit.obj, hit.hitpos);
	if (dot(hit.normal_vect, ray.dir) > 0)
		hit.normal_vect = sub((t_vec3){0.f, 0.f, 0.f}, hit.normal_vect);
	return (hit);
}
