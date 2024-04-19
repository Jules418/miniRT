/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:55:09 by lcamerly          #+#    #+#             */
/*   Updated: 2023/12/13 14:59:11 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_case_zero(char *dest)
{
	dest = malloc(sizeof(char) * 2);
	if (!dest)
		return (NULL);
	dest[0] = '0';
	dest[1] = '\0';
	return (dest);
}

static char	*tab_writing(int nb, unsigned int n, int index, char *dest)
{
	if (nb < 0)
		dest[0] = '-';
	dest[index--] = '\0';
	while (n > 9)
	{
		dest[index--] = n % 10 + '0';
		n = n / 10;
	}
	dest[index] = n % 10 + '0';
	return (dest);
}

static unsigned int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

char	*ft_itoa(int nb)
{
	unsigned int	nb_count;
	unsigned int	n;
	int				i;
	char			*dest;

	i = 1;
	if (nb == 0)
	{
		dest = NULL;
		return (ft_case_zero(dest));
	}
	if (nb < 0)
		i++;
	n = ft_abs(nb);
	nb_count = n;
	while (nb_count > 9)
	{
		nb_count = nb_count / 10;
		i++;
	}
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	return (tab_writing(nb, n, i, dest));
}
