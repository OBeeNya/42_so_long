/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:52:49 by baubigna          #+#    #+#             */
/*   Updated: 2022/02/06 15:04:05 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_nb_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	check_first_last(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 49)
			return (0);
		i++;
	}
	return (1);
}

int	check_middle(char *line)
{
	size_t	i;

	i = 0;
	if (line[i] != '1')
		return (0);
	i++;
	while (i < ft_strlen(line) - 1)
	{
		if (line[i] != 48 && line[i] != 49 && line[i] != 67
			&& line[i] != 69 && line[i] != 80)
			return (0);
		i++;
	}
	if (line[i] != 49)
		return (0);
	return (1);
}

int	check_width(char **map)
{
	size_t	l;

	l = ft_strlen(map[0]);
	while (*map)
	{
		if (ft_strlen(*map) != l)
			return (0);
		map++;
	}
	return (1);
}

int	check_map(char **map)
{
	int	i;

	i = 0;
	while (i < get_nb_lines(map))
	{
		if (i == 0 || i + 1 == get_nb_lines(map))
		{
			if (!check_first_last(map[i]))
				return (0);
		}
		else
			if (!check_middle(map[i]))
				return (0);
		i++;
	}
	if (!check_width(map))
		return (0);
	return (1);
}
