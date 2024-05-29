/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 21:03:11 by lcamerly          #+#    #+#             */
/*   Updated: 2024/05/29 21:51:01 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	skip_whitespace(const char **str)
{
	while (**str == ' ' || **str == '\t' || **str == '\n'
		|| **str == '\v' || **str == '\f' || **str == '\r')
		(*str)++;
}

static int	get_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

static double	get_integer_part(const char **str)
{
	double	result;

	result = 0.0;
	if (!ft_isdigit(**str))
		exit_error("Error\nInvalid character in file (ft_atof1)\n");
	while (ft_isdigit(**str))
	{
		result = result * 10.0 + (**str - '0');
		(*str)++;
	}
	return (result);
}

static double	get_fractional_part(const char **str)
{
	double	fraction;
	double	divisor;

	fraction = 0.0;
	divisor = 1.0;
	if (**str == '.')
	{
		(*str)++;
		if (!ft_isdigit(**str))
			exit_error("Error\nInvalid character in file (ft_atof2)\n");
		while (ft_isdigit(**str))
		{
			fraction = fraction * 10.0 + (**str - '0');
			divisor *= 10.0;
			(*str)++;
		}
	}
	return (fraction / divisor);
}

double	ft_atof(const char *str)
{
	double	integer_part;
	double	fractional_part;
	int		sign;

	skip_whitespace(&str);
	sign = get_sign(&str);
	integer_part = get_integer_part(&str);
	fractional_part = get_fractional_part(&str);
	return (sign * (integer_part + fractional_part));
}
