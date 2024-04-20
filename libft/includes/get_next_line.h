/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:55:54 by lcamerly          #+#    #+#             */
/*   Updated: 2024/01/18 14:41:01 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# if BUFFER_SIZE > 9223372036854775806
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# include <stdlib.h>
# include <unistd.h>

char	*ft_strdup_gnl(const char *s);
void	*ft_malloc_zero(size_t nmemb, size_t size);
char	*get_next_line(int fd);
char	*ft_parse_line(char **stash, char **temp);
char	*ft_get_after_newline(const char *s);
char	*ft_get_before_newline(const char *s);
void	ft_read_line(int fd, char **temp, char **stash);
int		has_newline_inside(char *s);
void	free_strs(char **str1, char **str2, char **str3);
char	*ft_strjoin(const char *s1, const char *s2);

#endif