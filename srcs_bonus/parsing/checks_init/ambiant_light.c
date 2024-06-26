/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiant_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:33:50 by lcamerly          #+#    #+#             */
/*   Updated: 2024/06/07 10:26:14 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

/*
** @brief Check if the ambiant light ratio is between 0 and 1
 and if the color is between 0 and 255
** @param char* s : Line to check
*/
void	check_ambientlight(char *s)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = gc_split(s, ' ');
	if (!tmp || len_split(tmp) != 3)
		exit_error("GC_SPLIT_ERROR");
	if (ft_atof(tmp[1]) < 0.0 || ft_atof(tmp[1]) > 1.0)
		exit_error("Ambiant light ratio must in range [0.0,1.0] !\
		\nExiting...\n");
	tmp = gc_split(tmp[2], ',');
	if (!tmp || len_split(tmp) <= 2)
		exit_error(GC_SPLIT_ERROR);
	while (tmp[i])
	{
		if (ft_atof(tmp[i]) < 0 || ft_atof(tmp[i]) > 255)
			exit_error("Ambiant light color (RGB) must be between [0,255] !\
			\nExiting...\n");
		i++;
	}
	printf("✅ Ambiant light OK !\n");
}

void	init_ambiantlight(char *s, t_minirt *minirt)
{
	char	**tmp;
	char	**tmp2;

	tmp = gc_split(s, ' ');
	if (!tmp)
		exit_error("Error in a malloc (parsing.c:92)");
	tmp2 = gc_split(tmp[2], ',');
	if (!tmp2)
		exit_error("Error in a malloc (parsing.c:93)");
	minirt->scene->ambient_light = scale((t_vec3)
		{(float)ft_atof(tmp2[0]) / 255,
			(float)ft_atof(tmp2[1]) / 255, (float)ft_atof(tmp2[2]) / 255},
			ft_atof(tmp[1]));
}
