/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:44:42 by lcamerly          #+#    #+#             */
/*   Updated: 2024/05/29 01:17:51 by lcamerly         ###   ########.fr       */
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

static bool	is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f'
		|| c == '\r');
}

double	ft_atof(const char *str)
{
	double	result;
	double	fraction;
	double	divisor;
	int		sign;
	bool	has_fraction;

	result = 0.0;
	fraction = 0.0;
	divisor = 1.0;
	sign = 1;
	has_fraction = false;
	if (*str == '.')
		exit_error("Error\nParameters can't start by a dot\n");
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		if (!ft_isdigit(*(str + 1)))
			exit_error("Error\nInvalid character in file (ft_atof1)\n");
		str++;
		has_fraction = true;
		while (ft_isdigit(*str))
		{
			fraction = fraction * 10.0 + (*str - '0');
			divisor *= 10.0;
			str++;
		}
	}
	else if (*str && *str != '\n')
		exit_error("Error\nInvalid character in file (ft_atof2)\n");
	if (has_fraction)
		result += fraction / divisor;
	return (sign * result);
}

void	exit_error(char *s)
{
	printf("%s", s);
	free_exit(42);
}
