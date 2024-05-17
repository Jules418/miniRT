/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:44:42 by lcamerly          #+#    #+#             */
/*   Updated: 2024/05/17 16:10:34 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_extension(char *filename)
{
	size_t	i;

	i = 0;
	while (filename[i])
		i++;
	if ((filename[i - 1] != 't' || filename[i - 2] != 'r' || filename[i
				- 3] != '.') && filename[i - 4])
	{
		printf("Error\nFile %s is not a .rt file\n", filename);
		exit(EXIT_FAILURE);
	}
	return (1);
}
