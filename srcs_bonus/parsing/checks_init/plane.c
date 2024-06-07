/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 01:35:13 by lcamerly          #+#    #+#             */
/*   Updated: 2024/06/07 10:26:14 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

/*
Plane:
pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225
- identifier: pl
- x,y,z coordinates of a point in the plane: 0.0,0.0,-10.0
- 3d normalized normal vector. In range [-1,1] for each x,y,z axis: 0.0,1.0,0.0
- R,G,B colors in range [0-255]: 0,0,225
*/
void	check_plane(char *s)
{
	char	**tmp;
	char	**tmp2;

	tmp = gc_split(s, ' ');
	if (!tmp || len_split(tmp) != 4)
		exit_error(GC_SPLIT_ERROR);
	tmp2 = gc_split(tmp[1], ',');
	if (!tmp2 || len_split(tmp2) != 3)
		exit_error(GC_SPLIT_ERROR);
	while (*tmp2)
		ft_atof(*tmp2++);
	tmp2 = gc_split(tmp[2], ',');
	if (!tmp2 || len_split(tmp2) != 3)
		exit_error(GC_SPLIT_ERROR);
	if (ft_atof(tmp2[0]) < -1 || ft_atof(tmp2[0]) > 1 || ft_atof(tmp2[1]) < -1
		|| ft_atof(tmp2[1]) > 1 || ft_atof(tmp2[2]) < -1 || ft_atof(tmp2[2]) > 1
		||!is_normalized(tmp2[0], tmp2[1], tmp2[2]))
		exit_error("Plane axis vector must be normalized ! \
		\nExiting...\n");
	tmp2 = gc_split(tmp[3], ',');
	if (!tmp2 || len_split(tmp2) != 3)
		exit_error(GC_SPLIT_ERROR);
	while (*tmp2)
		if (ft_atof(*tmp2) < 0 || ft_atof(*tmp2++) > 255)
			exit_error("Plane color (RGB) must be between [0,255] !\
			\nExiting...\n");
	printf("✅ Plane OK !\n");
}

void	init_plane(char *s, t_minirt *minirt)
{
	char		**tmp;
	char		**tmp2;
	t_plane		*pl;
	t_objects	*o;

	tmp = gc_split(s, ' ');
	if (!tmp)
		exit_error("Error\nMalloc failed in plane.c:60\nExiting...\n");
	tmp2 = gc_split(tmp[1], ',');
	if (!tmp2)
		exit_error("Error\nMalloc failed in plane.c:63\nExiting...\n");
	pl = malloc(sizeof(t_plane));
	pl->pos = (t_vec3){ft_atof(tmp2[0]), ft_atof(tmp2[1]), ft_atof(tmp2[2])};
	tmp2 = gc_split(tmp[2], ',');
	if (!tmp2)
		exit_error("Error\nMalloc failed in plane.c:68\nExiting...\n");
	pl->normal_vector = normalized((t_vec3){ft_atof(tmp2[0]), ft_atof(tmp2[1]),
			ft_atof(tmp2[2])});
	tmp2 = gc_split(tmp[3], ',');
	if (!tmp2)
		exit_error("Error\nMalloc failed in plane.c:73\nExiting...\n");
	o = create_obj(plane, pl, (t_vec3){ft_atof(tmp2[0]) / 255, ft_atof(tmp2[1])
			/ 255, ft_atof(tmp2[2]) / 255});
	ft_lstadd_back(&minirt->scene->objects, ft_lstnew(o));
}
