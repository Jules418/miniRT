/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:44:42 by lcamerly          #+#    #+#             */
/*   Updated: 2024/05/27 18:13:06 by lcamerly         ###   ########.fr       */
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
		exit_error("Error\nWrong file extension\n");
	}
	return (1);
}

float	parse_decimal(char *s, int *index)
{
	float	dec;
	float	res;

	dec = 1;
	res = 0;
	while (s[*index])
	{
		dec /= 10;
		res += dec * (s[*index] - '0');
		(*index)++;
	}
	return (res);
}

float	ft_atof(char *s)
{
	float	res;
	int		i;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
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

void	exit_error(char *s)
{
	printf("%s\n", s);
	free_exit(42);
}
