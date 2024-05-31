/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamerly <lcamerly@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:53:22 by lcamerly          #+#    #+#             */
/*   Updated: 2024/05/31 07:12:11 by lcamerly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_chars(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		if (!s[i][0] || !s[i][1])
			break ;
		j = 2;
		while (s[i][j])
		{
			if (s[i][j] != ' ' && s[i][j] != ',' && s[i][j] != '.'
				&& s[i][j] != '-' && s[i][j] != '\n' && !ft_isdigit(s[i][j]))
				exit_error("Error\nInvalid character in file\n");
			j++;
		}
		i++;
	}
}

char	**parsing(char **av)
{
	int		fd;
	int		count;
	char	**res;

	fd = open_file(av[1]);
	count = pre_read(fd);
	fd = open_file(av[1]);
	res = read_file(fd, count);
	close(fd);
	check_chars(res);
	return (res);
}
	//TODO Ajouter un compteur d'arguments pour chaques lignes
