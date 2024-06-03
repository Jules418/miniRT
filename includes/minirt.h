/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:49:40 by jules             #+#    #+#             */
/*   Updated: 2024/06/03 17:52:14 by jules            ###   ########.fr       */
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
# include <pthread.h>

# ifndef M_PI
#  define M_PI 3.14159265359f
# endif

# define TEMP_WIDTH 1024
# define TEMP_HEIGHT 640

# ifndef NB_THREADS
#  define NB_THREADS 8
# endif

typedef struct s_camera
{
	t_vec3	pos;
	t_vec3	forward;
	t_vec3	up;
	t_vec3	right;
	float	fov;
	float	d_to_screen;
}	t_camera;

typedef struct s_double_list
{
	t_camera				*content;
	struct s_double_list	*next;
	struct s_double_list	*prev;
}	t_dlist;

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


typedef struct s_light
{
	t_vec3	pos;
	t_vec3	color;
	float	brightness;
}	t_light;

typedef struct s_scene
{
	t_list		*objects;
	t_dlist		*cameras;
	t_list		*lights;
	t_vec3		ambient_light; // color * brightness
	int			height;
	int			width;
	int			should_render;
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

typedef struct s_threadarg
{
	t_minirt	*minirt;
	int			start;
	int			end;
}	t_threadarg;



void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		init_minirt(t_minirt *minirt);
void		free_scene(t_scene scene);
int			close_minirt(t_minirt *minirt);

void		exit_error(char *s);
size_t		len_split(char **s);

float		cast_ray(t_ray ray, t_objects *obj);
t_hitpoint	get_hitpoint(t_scene scene, t_ray ray);

int			vec_to_rgb(t_vec3 u);
t_vec3		find_normal(t_objects *obj, t_vec3 hit_pos);
t_vec3		diffuse_light(t_hitpoint hit, t_light *light);
int			in_light(t_scene scene, t_hitpoint hit, t_light *light);
t_vec3		specular_light(t_ray ray, t_hitpoint hit, t_light *light);

void		yaw(int key, t_dlist *minirt);
void		pitch(int key, t_dlist *minirt);
void		roll(int key, t_dlist *minirt);
void		move_camera(int key, t_minirt *minirt);

int			render_scene(t_minirt *minirt);
int			input(int key, t_minirt *minirt);

char		**parsing(char **av);
int			pre_read(int fd);
int			close_file(int fd);
int			open_file(char *filename);
char		**read_file(int fd, int nb_lines);
double		ft_atof(const char *str);

bool		check_name(char *line, char *name);
int			check_extension(char *filename);
void		check_ambientlight(char *s);
void		check_chars(char **s);
void		check_camera(char *s);
void		check_light(char *s);
void		check_sphere(char *s);
void		check_plane(char *s);
void		check_cylinder(char *s);
void		check_everything(char **map);
void		check_rgb_cylinder(char **tmp2);
void		check_cone(char *s);

void		setup_direction(t_camera *cam, t_minirt *minirt);

void		init_ambiantlight(char *s, t_minirt *minirt);
void		init_camera(char *s, t_minirt *minirt);
void		init_light(char *s, t_minirt *minirt);
void		init_sphere(char *s, t_minirt *minirt);
void		init_plane(char *s, t_minirt *minirt);
void		init_cylinder(char *s, t_minirt *minirt);
void		create_cylinder_obj(t_cylinder *cy, char **tmp2, t_minirt *minirt);
void		init_everything(char **map, t_minirt *minirt);
void		init_scene(char **map, t_minirt *minirt);
void		init_cone(char *s, t_minirt *minirt);
void		create_cone_obj(t_minirt *minirt, t_cone *c, char *s);

t_objects	*create_obj(t_type type, void *obj, t_vec3 color);

t_dlist		*ft_dlstlast(t_dlist *lst);
t_dlist		*ft_dlstnew(void *content);
void		ft_dlstadd_back(t_dlist **alst, t_dlist *new);
t_dlist		*ft_dlistfirst(t_dlist *lst);

void		multicam(int key, t_minirt* minirt);

#endif