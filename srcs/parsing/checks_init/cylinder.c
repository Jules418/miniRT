/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 03:27:16 by lcamerly          #+#    #+#             */
/*   Updated: 2024/05/29 03:37:08 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
Cylinder:
cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
- identifier: cy
- x,y,z coordinates of the center of the cylinder: 50.0,0.0,20.6
- 3d normalized vector of axis of cylinder. In range [-1,1] for each x,y,z axis:
0.0,0.0,1.0
- the cylinder diameter: 14.2
- the cylinder height: 21.42
- R,G,B colors in range [0,255]: 10, 0, 255
*/

void check_cylinder(char *s)
{
    char **tmp;
    char **tmp2;
    
    tmp = gc_split(s, ' ');
    if (!tmp)
        exit_error("Error\nMalloc failed in cylinder.c:29\nExiting...\n");
    tmp2 = gc_split(tmp[1], ',');
    if (!tmp2)
        exit_error("Error\nMalloc failed in cylinder.c:32\nExiting...\n");
    while (*tmp2)
        ft_atof(*tmp2++);
    tmp2 = gc_split(tmp[2], ',');
    while (*tmp2)
        if (ft_atof(*tmp2) < -1 || ft_atof(*tmp2++) > 1)
            exit_error("Cylinder axis vector must be normalized !\nExiting...\n");
    if (ft_atof(tmp[3]) < 0)
        exit_error("Cylinder diameter must be positive !\nExiting...\n");
    if (ft_atof(tmp[4]) < 0)
        exit_error("Cylinder height must be positive !\nExiting...\n");
    tmp2 = gc_split(tmp[5], ',');
    while (*tmp2)
        if (ft_atof(*tmp2) < 0 || ft_atof(*tmp2++) > 255)
            exit_error("Cylinder color (RGB) must be between [0,255] !\nExiting...\n");
    printf("✅ Cylinder OK !\n");
}

void init_cylinder(char *s, t_minirt *minirt)
{
    char **tmp;
    char **tmp2;
    t_cylinder *cy;
    t_objects o;

    (void)minirt;
    tmp = gc_split(s, ' ');
    if (!tmp)
        exit_error("Error\nMalloc failed in cylinder.c:55\nExiting...\n");
    tmp2 = gc_split(tmp[1], ',');
    if (!tmp2)
        exit_error("Error\nMalloc failed in cylinder.c:58\nExiting...\n");
    cy = malloc(sizeof(t_cylinder));
    if (!cy)
        exit_error("Error\nMalloc failed in cylinder.c:61\nExiting...\n");
    cy->pos = (t_vec3){ft_atof(tmp2[0]), ft_atof(tmp2[1]), ft_atof(tmp2[2])};
    cy->height = ft_atof(tmp[4]);
    cy->width = ft_atof(tmp[3]);
    tmp2 = gc_split(tmp[2], ',');
    if (!tmp2)
        exit_error("Error\nMalloc failed in cylinder.c:66\nExiting...\n");  
    cy->dir = normalize(&(t_vec3){ft_atof(tmp2[0]), ft_atof(tmp2[1]), ft_atof(tmp2[2])});
    tmp2 = gc_split(tmp[5], ',');
    if (!tmp2)
        exit_error("Error\nMalloc failed in cylinder.c:70\nExiting...\n");
    o = create_obj(cylinder, cy, (t_vec3){ft_atof(*tmp2) / 255, ft_atof(*(tmp2 + 1)) / 255, ft_atof(*(tmp2 + 2)) / 255});
    minirt->scene->objects[2] = o;
}
