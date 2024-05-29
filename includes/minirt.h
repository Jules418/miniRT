/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:49:40 by jules             #+#    #+#             */
/*   Updated: 2024/05/29 22:13:18 by lcamerly         ###   ########.fr       */
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
# include "libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <limits.h>

# ifndef M_PI
#  define M_PI 3.14159265359f
# endif

# define TEMP_WIDTH 1024
# define TEMP_HEIGHT 640

typedef enum s_alloc_enum
{
	NEW,
	FREE_ONE,
	FULL_FREE,
	NONE
}	t_alloc_enum;

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
	plane,
	cone
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
	t_list		*objects;
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

typedef struct s_alloc
{
	void			*alloc;
	struct s_alloc	*next;
}	t_alloc;


//			GARBAGE COLLECTOR			//
void		alloc_handler(void *alloc, t_alloc_enum opcode);
void		*f_malloc(size_t len);
void		free_exit(int code);
void		single_free(void *alloc, t_alloc *actual);
void		full_free(t_alloc *first);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_alloc		*new_alloc(void *alloc);
void		f_free(void *alloc);
char		**gc_split(char const *s, char c);
char		*gc_strdup(const char *s);

t_minirt	init_minirt(int argc, char **argv);
void		free_scene(t_scene scene);
int			close_minirt(t_minirt *minirt);

void		exit_error(char *s);

t_scene		test_scene(void);

float		cast_ray(t_ray ray, t_objects *obj);
t_hitpoint	get_hitpoint(t_scene scene, t_ray ray);

t_vec3		find_normal(t_objects *obj, t_vec3 hit_pos);
t_vec3		diffuse_light(t_scene scene, t_hitpoint hit);
int			in_light(t_scene scene, t_hitpoint hit);
t_vec3		specular_light(t_scene sc, t_ray ray, t_hitpoint hit);

void		render_scene(t_minirt *minirt);
int			input(int key, t_minirt *minirt);

char		**parsing(char **av);
int			pre_read(int fd);
int			close_file(int fd);
int			open_file(char *filename);
char		**read_file(int fd, int nb_lines);
double		ft_atof(const char *str);
void		setup_direction(t_minirt *minirt, char **tmp2);
bool 		check_name(char *line, char* name);
int			check_extension(char *filename);
void		check_ambientlight(char *s);
void		check_chars(char **s);
void		check_camera(char *s);
void		check_light(char *s);
void 		check_sphere(char *s);
void 		check_plane(char *s);
void 		check_cylinder(char *s);
void 		check_everything(char **map);
void		init_ambiantlight(char *s, t_minirt *minirt);
void 		init_camera(char *s, t_minirt* minirt);
void		init_light(char *s, t_minirt *minirt);
void	 	init_sphere(char *s, t_minirt *minirt);
void	 	init_plane(char *s, t_minirt *minirt);
void 		init_cylinder(char *s, t_minirt *minirt);
void 		init_everything(char **map, t_minirt* minirt);
void 		init_scene(char **map, t_minirt *minirt);
t_objects 	*create_obj(t_type type, void *obj, t_vec3 color);
void 		create_cylinder_obj(t_cylinder *cy, char** tmp2, t_minirt *minirt);
void check_rgb_cylinder(char **tmp2);

#endif