/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:05:42 by lcamerly          #+#    #+#             */
/*   Updated: 2024/06/03 17:29:02 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
Camera:
C -50.0,0,20 0,0,1 70
- identifier: C
- x,y,z coordinates of the view point: -50.0,0,20
- 3d normalized orientation vector. In range [-1,1] for each x,y,z axis:
0.0,0.0,1.0
- FOV : Horizontal field of view in degrees in range [0,180]: 70
*/
void	check_camera(char *s)
{
	char	**tmp;
	char	**tmp2;

	tmp = gc_split(s, ' ');
	if (!tmp || len_split(tmp) < 4)
		exit_error("Error\nMalloc failed in camera.c:19\nExiting...\n");
	tmp2 = gc_split(tmp[1], ',');
	if (!tmp2 || len_split(tmp2) != 3)
		exit_error("Error\nMalloc failed in camera.c:20\nExiting...\n");
	while (*tmp2)
		ft_atof(*tmp2++);
	tmp2 = gc_split(tmp[2], ',');
	if (!tmp2 || len_split(tmp2) != 3)
		exit_error("Error\nMalloc failed in camera.c:21\nExiting...\n");
	if ((ft_atof(*tmp2) > 1.f || ft_atof(*tmp2) < -1.f) || (ft_atof(*(tmp2
					+ 1)) > 1.f || ft_atof(*(tmp2 + 1)) < -1.f)
		|| (ft_atof(*(tmp2 + 2)) > 1.f || ft_atof(*(tmp2 + 2)) < -1.f))
		exit_error("Error\nCamera orientation must be in range[-1.0, \
			1.0]\nExiting...\n");
	if (ft_atof(*(tmp + 3)) < 0.f || ft_atof(*(tmp + 3)) > 180.f)
		exit_error("Error\nCamera FOV must be in range[0.0, \
			180.0]\nExiting...\n");
	printf("✅ Camera OK !\n");
}

void	init_camera(char *s, t_minirt *minirt)
{
	char		**tmp;
	char		**tmp2;
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	tmp = gc_split(s, ' ');
	if (!tmp)
		exit_error("Error\nMalloc failed in camera.c:47\nExiting...\n");
	tmp2 = gc_split(tmp[1], ',');
	if (!tmp2)
		exit_error("Error\nMalloc failed in camera.c:47\nExiting...\n");
	cam->pos = (t_vec3){ft_atof(*tmp2), ft_atof(*(tmp2 + 1)),
		ft_atof(*(tmp2 + 2))};
	cam->fov = ft_atof(*(tmp + 3)) * 2.f * M_PI / 360.f;
	tmp2 = gc_split(tmp[2], ',');
	if (!tmp2)
		exit_error("Error\nMalloc failed in camera.c:53\nExiting...\n");
	cam->forward = (t_vec3){ft_atof(*tmp2), ft_atof(*(tmp2 + 1)),
		ft_atof(*(tmp2 + 2))};
	if (fabs(mag2(cam->forward) - 1.f) > EPSILON)
		exit_error("Error\nCamera orientation should be normalized\n\
Exiting...\n");
	cam->d_to_screen = 1.f / tanf(cam->fov / 2.f);
	setup_direction(cam, minirt);
}

void	setup_direction(t_camera *cam, t_minirt *minirt)
{
	t_vec3	dir;

	dir = (t_vec3){0.f, 1.f, 0.f};
	cam->right = cross(cam->forward, dir);
	if (mag2(cam->right) < EPSILON)
		cam->right = cross(cam->forward,
				(t_vec3){0.f, 0.f, 1.f});
	cam->up = cross(cam->right,
			cam->forward);
	normalize(&cam->forward);
	normalize(&cam->up);
	normalize(&cam->right);
	ft_dlstadd_back(&minirt->scene->cameras, ft_dlstnew(cam));
}
