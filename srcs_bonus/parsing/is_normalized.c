/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_normalized.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:34:35 by jules             #+#    #+#             */
/*   Updated: 2024/06/07 10:26:14 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

bool	is_normalized(char *x, char *y, char *z)
{
	t_vec3	u;
	float	l2;

	u = (t_vec3){ft_atof(x), ft_atof(y), ft_atof(z)};
	l2 = mag2(u);
	return (fabs(l2 - 1.f) < EPSILON);
}
