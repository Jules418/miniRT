/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:44:42 by lcamerly          #+#    #+#             */
/*   Updated: 2024/05/26 20:40:01 by lcamerly         ###   ########.fr       */
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

float parse_decimal(char *s, int *index)
{
	float dec = 1;
	float res = 0;
	while (s[*index])
	{
		dec /= 10;
		res += dec * (s[*index] - '0');
		(*index)++;
	}
	return res;
}

float ft_atof(char *s)
{
	float res = 0;
	int i = 0;
	int sign = 1;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (s[i] && s[i] != '.')
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	if (s[i] == '.')
	{
		i++;
		res += parse_decimal(s, &i);
	}
	return (res * sign);
}