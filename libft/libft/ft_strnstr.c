/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:33:52 by lcamerly          #+#    #+#             */
/*   Updated: 2023/12/13 14:59:10 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*to_find)
		return (str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] && to_find[j] && str[i + j] == to_find[j] && i
			+ j < len)
			j++;
		if (!to_find[j])
			return (&str[i]);
		i++;
	}
	return (NULL);
}
