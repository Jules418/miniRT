/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:56:40 by lcamerly          #+#    #+#             */
/*   Updated: 2023/12/13 14:59:10 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char c, char const *set)
{
	while (*set)
	{
		if (*set++ == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len;
	size_t	i;

	i = 0;
	if (!s1 || !set)
		return ((char *)0);
	while (*s1 && ft_is_set(*s1, set))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_is_set(s1[len - 1], set))
		len--;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return ((char *)0);
	while (i < len)
		str[i++] = *s1++;
	str[i] = 0;
	return (str);
}
