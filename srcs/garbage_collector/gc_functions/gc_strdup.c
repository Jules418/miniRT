/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:49:27 by lcamerly          #+#    #+#             */
/*   Updated: 2024/05/27 18:11:06 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*gc_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*dest;

	len = 0;
	i = 0;
	while (s[len])
		len++;
	dest = f_malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
