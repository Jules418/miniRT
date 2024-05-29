/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 22:48:34 by jules             #+#    #+#             */
/*   Updated: 2024/05/29 22:50:11 by jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGE_COLLECTOR_H
# define GARBAGE_COLLECTOR_H

# include <stdlib.h>

typedef enum s_alloc_enum
{
	NEW,
	FREE_ONE,
	FULL_FREE,
	NONE
}	t_alloc_enum;

typedef struct s_alloc
{
	void			*alloc;
	struct s_alloc	*next;
}	t_alloc;

void		alloc_handler(void *alloc, t_alloc_enum opcode);
void		*f_malloc(size_t len);
void		free_exit(int code);
void		single_free(void *alloc, t_alloc *actual);
void		full_free(t_alloc *first);
t_alloc		*new_alloc(void *alloc);
void		f_free(void *alloc);
char		**gc_split(char const *s, char c);
char		*gc_strdup(const char *s);

#endif