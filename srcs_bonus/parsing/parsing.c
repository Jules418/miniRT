/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbanacze <jbanacze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:53:22 by lcamerly          #+#    #+#             */
/*   Updated: 2024/06/07 10:26:14 by jbanacze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

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
			if (s[i][j] == '\n')
				s[i][j] = '\0';
			j++;
		}
		i++;
	}
}

size_t	len_split(char **s)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
			j++;
		i++;
	}
	return (i);
}

void	check_comma(char **s)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == ',')
				if (s[i][j + 1] == ',' || s[i][j - 1] == ',')
					exit_error("Error\nInvalid comma in file\n");
			if (s[i][j] == ',')
				if (s[i][j + 1] == '\0')
					exit_error("Error\nInvalid comma in file\n");
			if (s[i][j] == ' ')
				if (s[i][j + 1] == ',' || s[i][j - 1] == ',')
					exit_error("Error\nInvalid comma in file\n");
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

	check_extension(av[1]);
	fd = open_file(av[1]);
	count = pre_read(fd);
	fd = open_file(av[1]);
	res = read_file(fd, count);
	close(fd);
	check_chars(res);
	check_comma(res);
	return (res);
}
