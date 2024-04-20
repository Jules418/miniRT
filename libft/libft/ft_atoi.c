/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:54:45 by lcamerly          #+#    #+#             */
/*   Updated: 2023/12/13 14:59:11 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\r' || c == '\f'
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	long long	minus;
	long long	nb;

	i = 0;
	minus = 1;
	nb = 0;
	while (is_whitespace(str[i]))
		i++;
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		if (nb != ((nb * 10) + (str[i] - 48)) / 10)
			return ((minus + 1) / -2);
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return ((int)nb * minus);
}
