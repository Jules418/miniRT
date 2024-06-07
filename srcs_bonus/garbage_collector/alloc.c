/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:58:29 by lcamerly          #+#    #+#             */
/*   Updated: 2024/06/07 10:26:14 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_alloc	*new_alloc(void *alloc)
{
	t_alloc	*temp;

	temp = malloc(sizeof(t_alloc));
	if (!temp)
		return (NULL);
	temp->alloc = alloc;
	temp->next = NULL;
	return (temp);
}

void	*f_malloc(size_t len)
{
	void	*alloc;

	alloc = malloc(len);
	alloc_handler(alloc, NONE);
	return (alloc);
}
