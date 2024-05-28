/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:58:09 by lcamerly          #+#    #+#             */
/*   Updated: 2024/05/28 14:08:51 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	full_free(t_alloc *first)
{
	t_alloc	*actual;
	t_alloc	*temp;

	actual = first;
	while (actual)
	{
		if (actual->alloc)
			free(actual->alloc);
		temp = actual->next;
		free(actual);
		actual = temp;
	}
}

void	single_free(void *alloc, t_alloc *actual)
{
	t_alloc	*old;

	old = NULL;
	while (actual && actual->alloc != alloc)
	{
		old = actual;
		actual = actual->next;
	}
	if (actual)
	{
		free(actual->alloc);
		actual->alloc = NULL;
		if (old)
		{
			old->next = actual->next;
			free(actual);
		}
	}
	else
		free(alloc);
	return ;
}

void	free_exit(int code)
{
	alloc_handler(NULL, FULL_FREE);
	exit(code);
}

void	f_free(void *alloc)
{
	alloc_handler(alloc, FREE_ONE);
}
