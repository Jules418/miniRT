/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:49:40 by jules             #+#    #+#             */
/*   Updated: 2024/04/22 14:38:57 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <mlx.h>
# include <mlx_int.h>
# include <stdlib.h>
# include <math.h>
# include "geometry.h"
# include "vector.h"

# ifndef M_PI
#  define M_PI 3.14159265359f
# endif

# define TEMP_WIDTH 800
# define TEMP_HEIGHT 640

typedef struct s_data
{
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef enum e_type
{
	sphere,
	cylinder,
	plane
}	t_type;

typedef struct s_object
{
	t_type	obj_type;
	void	*obj;
	t_vec3	color;
}	t_objects;

typedef struct s_camera
{
	t_vec3	pos;
	t_vec3	forward;
	t_vec3	up;
	t_vec3	right;
	float	fov;
}	t_camera;

typedef struct s_light
{
	t_vec3	pos;
	t_vec3	color;
	float	brightness;
}	t_light;

typedef struct s_scene
{
	t_objects	objects[10];
	int			nb_objects;
	t_camera	cam;
	t_light		light;
	t_vec3		ambient_light; // color * brightness
	int			height;
	int			width;
	int			should_render;
	float		d_to_screen;
}	*t_scene;

typedef struct s_hitpoint
{
	float		d;
	t_objects	*obj;
	t_vec3		hitpos;
	t_vec3		normal_vect;
}	t_hitpoint;

typedef struct s_minirt
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_scene	scene;
}	t_minirt;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

t_minirt	init_minirt(int argc, char **argv);
void		free_scene(t_scene scene);
int			close_minirt(t_minirt *minirt);

t_scene		test_scene(void);

float		cast_ray(t_ray ray, t_objects *obj);
t_hitpoint	get_hitpoint(t_scene scene, t_ray ray);

t_vec3		find_normal(t_objects *obj, t_vec3 hit_pos);
t_vec3		diffuse_light(t_scene scene, t_hitpoint hit);
int			in_light(t_scene scene, t_hitpoint hit);

void		render_scene(t_minirt *minirt);
int			input(int key, t_minirt *minirt);

#endif