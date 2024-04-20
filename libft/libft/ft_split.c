/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:55:39 by lcamerly          #+#    #+#             */
/*   Updated: 2023/12/13 14:59:11 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(char const *str, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			words++;
		while (str[i] && (!(str[i] == c)))
			i++;
	}
	return (words);
}

static size_t	ft_size_word(char const *s, char c, int i)
{
	size_t	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static void	ft_free(char **strs, int j)
{
	while (j >= 0)
	{
		free(strs[j]);
		j--;
	}
	free(strs);
}

static size_t	ft_add_words(char **strs, char const *s, char c, size_t word)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = 0;
	while (j < word)
	{
		while (s[i] && s[i] == c)
			i++;
		size = ft_size_word(s, c, i);
		strs[j] = malloc(sizeof(char) * (size + 1));
		if (!strs[j])
		{
			ft_free(strs, j);
			return (0);
		}
		ft_strlcpy(strs[j], &s[i], size + 1);
		i += size;
		j++;
	}
	strs[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	count_of_words;
	int		check;

	if (!s)
		return (NULL);
	count_of_words = ft_count_word(s, c);
	strs = malloc(sizeof(char *) * (count_of_words + 1));
	if (!strs)
		return (NULL);
	check = ft_add_words(strs, s, c, count_of_words);
	if (!check)
		return (NULL);
	return (strs);
}
