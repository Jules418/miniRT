/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 02:20:43 by jules             #+#    #+#             */
/*   Updated: 2024/06/07 10:26:14 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int	vec_to_rgb(t_vec3 u)
{
	int	r;
	int	g;
	int	b;

	r = (int)(fmaxf(fminf(u.x * 255.f, 255.f), 0.f));
	g = (int)(fmaxf(fminf(u.y * 255.f, 255.f), 0.f));
	b = (int)(fmaxf(fminf(u.z * 255.f, 255.f), 0.f));
	return ((r << 16) | (g << 8) | b);
}

t_vec3	find_normal(t_objects *obj, t_vec3 hit_pos)
{
	if (!obj)
		return ((t_vec3){1.f, 0.f, 0.f});
	if (obj->obj_type == (t_type)sphere)
		return (sphere_normal(*(t_sphere *)obj->obj, hit_pos));
	if (obj->obj_type == (t_type)plane)
		return (plane_normal(*(t_plane *)obj->obj, hit_pos));
	if (obj->obj_type == (t_type)cylinder)
		return (cylinder_normal(*(t_cylinder *)obj->obj, hit_pos));
	if (obj->obj_type == (t_type)cone)
		return (cone_normal(*(t_cone *)obj->obj, hit_pos));
	return ((t_vec3){1.f, 0.f, 0.f});
}

t_vec3	diffuse_light(t_hitpoint hit, t_light *light)
{
	t_vec3	to_light;
	t_vec3	tmp_col;

	to_light = normalized(sub(light->pos, hit.hitpos));
	tmp_col = scale(light->color, light->brightness * fmaxf(0.f,
				dot(to_light, hit.normal_vect)));
	return (mult(hit.obj->color, tmp_col));
}

int	in_light(t_scene scene, t_hitpoint hit, t_light *light)
{
	t_vec3		to_light;
	float		dist_to_light;
	t_ray		ray;
	t_hitpoint	new_hit;

	to_light = sub(light->pos, hit.hitpos);
	dist_to_light = mag(to_light);
	to_light = scale(to_light, 1.f / dist_to_light);
	ray.origin = add(hit.hitpos, scale(hit.normal_vect, EPSILON));
	ray.dir = to_light;
	new_hit = get_hitpoint(scene, ray);
	if ((new_hit.d < 0.f) || (new_hit.d >= dist_to_light))
		return (1);
	return (0);
}

t_vec3	specular_light(t_ray ray, t_hitpoint hit, t_light *light)
{
	t_vec3	to_light;
	t_vec3	reflected_ray;
	t_vec3	color;
	float	spec_light_intensity;

	reflected_ray = reflect(ray.dir, hit.normal_vect);
	to_light = normalized(sub(light->pos, hit.hitpos));
	color = light->color;
	spec_light_intensity = dot(reflected_ray, to_light);
	if (spec_light_intensity <= EPSILON)
		return ((t_vec3){0.f, 0.f, 0.f});
	spec_light_intensity = powf(spec_light_intensity, 12.f);
	color = scale(color, spec_light_intensity);
	return (color);
}
