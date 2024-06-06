/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:45:13 by lcamerly          #+#    #+#             */
/*   Updated: 2024/06/06 11:21:28 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	exit_error(char *s)
{
	printf("%s", s);
	free_exit(42);
}

int	close_file(int fd)
{
	if (close(fd) == -1)
		exit_error("Error\nCould not close file\n");
	return (0);
}
