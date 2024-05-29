/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:05:42 by lcamerly          #+#    #+#             */
/*   Updated: 2024/05/29 13:31:05 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void check_camera(char *s)
{
    char **tmp;
    char **tmp2;

    tmp = gc_split(s, ' ');
    if (!tmp)
        exit_error("Error\nMalloc failed in camera.c:19\nExiting...\n");
    tmp2 = gc_split(tmp[1], ',');
    if (!tmp2)
        exit_error("Error\nMalloc failed in camera.c:19\nExiting...\n");
    while (*tmp2)
        ft_atof(*tmp2++);
    tmp2 = gc_split(tmp[2], ',');
    if (!tmp2)
        exit_error("Error\nMalloc failed in camera.c:19\nExiting...\n");
    if ((ft_atof(*tmp2) > 1.f || ft_atof(*tmp2) < 0.f ) 
        || (ft_atof(*(tmp2 + 1)) > 1.f || ft_atof(*(tmp2 + 1)) < 0.f )
        || (ft_atof(*(tmp2 + 2)) > 1.f || ft_atof(*(tmp2 + 2)) < 0.f ))
        exit_error("Error\nCamera orientation must be in range[0.0, 1.0]\nExiting...\n");
    if (ft_atof(*(tmp + 3)) < 0.f || ft_atof(*(tmp + 3)) > 180.f)
         exit_error("Error\nCamera FOV must be in range[0.0, 180.0]\nExiting...\n");
    printf("✅ Camera OK !\n");
}


void init_camera(char *s, t_minirt* minirt)
{
	char **tmp;
	char **tmp2;

	tmp = gc_split(s, ' ');
    if (!tmp)
        exit_error("Error\nMalloc failed in camera.c:47\nExiting...\n");
    tmp2 = gc_split(tmp[1], ',');
    if (!tmp2)
        exit_error("Error\nMalloc failed in camera.c:47\nExiting...\n");
    minirt->scene->cam.pos = (t_vec3){ft_atof(*tmp2), ft_atof(*(tmp2 + 1)), ft_atof(*(tmp2 + 2))};
    minirt->scene->cam.fov = ft_atof(*(tmp + 3)) * 2.f * M_PI / 360.f;
    tmp2 = gc_split(tmp[2], ',');
    if (!tmp2)
        exit_error("Error\nMalloc failed in camera.c:53\nExiting...\n");
    minirt->scene->d_to_screen = 1.f / tanf(minirt->scene->cam.fov / 2.f);
    setup_direction(minirt, tmp2);
}

void setup_direction(t_minirt *minirt, char **tmp2)
{

    t_vec3 dir;

    dir = (t_vec3){0.f, 1.f, 0.f};
    minirt->scene->cam.forward = (t_vec3){ft_atof(*tmp2), ft_atof(*(tmp2 + 1)), ft_atof(*(tmp2 + 2))};
    minirt->scene->cam.right = cross(minirt->scene->cam.forward, dir);
    if (mag2(minirt->scene->cam.right) < EPSILON)
         minirt->scene->cam.right = cross(minirt->scene->cam.forward, (t_vec3){0.f, 0.f, 1.f});
    minirt->scene->cam.up = cross(minirt->scene->cam.right, minirt->scene->cam.forward);
}