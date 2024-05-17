/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:45:13 by lcamerly          #+#    #+#             */
/*   Updated: 2024/05/17 16:10:13 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	close_file(int fd)
{
	if (close(fd) == -1)
	{
		printf("Error\nCould not close file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
