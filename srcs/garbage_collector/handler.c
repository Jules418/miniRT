/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:58:43 by lcamerly          #+#    #+#             */
/*   Updated: 2024/05/27 18:11:56 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** @brief Add or delete an allocation to the list of allocations
** @param void* Alloc The allocation to add or delete
** @param t_alloc_enum FULL_FREE or FREE_ONE
*/
void	alloc_handler(void *alloc, t_alloc_enum opcode)
{
	static t_alloc	*first = NULL;
	t_alloc			*temp;

	if (opcode == FULL_FREE)
	{
		full_free(first);
		return ;
	}
	if (opcode == FREE_ONE)
	{
		single_free(alloc, first);
		return ;
	}
	if (!first)
	{
		first = new_alloc(alloc);
		return ;
	}
	temp = first;
	while (temp->next)
		temp = temp->next;
	temp->next = new_alloc(alloc);
}
