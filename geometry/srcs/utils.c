/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:21:30 by jules             #+#    #+#             */
/*   Updated: 2024/04/16 15:46:06 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	solve_quadratic(float coefs[6])
{
	float	delta;
	float	x;

	delta = (coefs[1] * coefs[1]) - (4 * coefs[0] * coefs[2]);
	coefs[3] = delta;
	if (delta < 0.f)
		return ;
	if (delta == 0.f)
	{
		x = (-coefs[1]) / (2.f * coefs[0]);
		coefs[4] = x;
		coefs[5] = x;
		return ;
	}
	coefs[4] = (-coefs[1] - sqrtf(delta)) / (2.f * coefs[0]);
	coefs[5] = (-coefs[1] + sqrtf(delta)) / (2.f * coefs[0]);
}
