/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:44:42 by lcamerly          #+#    #+#             */
/*   Updated: 2024/06/06 11:55:45 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_extension(char *filename)
{
	size_t	i;

	i = 0;
	while (filename[i])
		i++;
	if (i < 4)
		exit_error("Error\nWrong file extension\n");
	if (filename[i - 1] != 't' || filename[i - 2] != 'r' || \
											filename[i - 3] != '.')
		exit_error("Error\nWrong file extension\n");
	return (1);
}
