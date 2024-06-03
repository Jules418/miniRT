/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multicam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:58:39 by lcamerly          #+#    #+#             */
/*   Updated: 2024/06/03 17:28:38 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	multicam(int key, t_minirt *minirt)
{
	if (key == XK_o || key == XK_p)
		minirt->scene->should_render = true;
	if (key == XK_o)
	{
		if (minirt->scene->cameras->next)
			minirt->scene->cameras = minirt->scene->cameras->next;
		else
			minirt->scene->cameras = ft_dlistfirst(minirt->scene->cameras);
	}
	if (key == XK_p)
	{
		if (minirt->scene->cameras->prev)
			minirt->scene->cameras = minirt->scene->cameras->prev;
		else
			minirt->scene->cameras = ft_dlstlast(minirt->scene->cameras);
	}
}

void	ft_dlstadd_back(t_dlist **alst, t_dlist *new)
{
	t_dlist	*last;

	if (!new)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	last = ft_dlstlast(*alst);
	last->next = new;
	new->prev = last;
}

t_dlist	*ft_dlstlast(t_dlist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_dlist	*ft_dlstnew(void *content)
{
	t_dlist	*new;

	new = malloc(sizeof(t_dlist));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_dlist	*ft_dlistfirst(t_dlist *lst)
{
	if (!lst)
		return (NULL);
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}
