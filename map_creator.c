/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:53:23 by baubigna          #+#    #+#             */
/*   Updated: 2022/02/09 09:19:50 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_filename(char *filename)
{
	size_t	l;

	if (ft_strlen(filename) < 10)
		return (0);
	l = ft_strlen(filename);
	if (filename[l - 1] != 'r' || filename[l - 2] != 'e'
		|| filename[l - 3] != 'b' || filename[l - 4] != '.')
		return (0);
	return (1);
}

char	**create_map(char *map_path)
{
	int		fd;
	char	*line;
	char	*full;
	char	*temp;
	char	**map;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
		return (0);
	full = ft_strdup("");
	while (line)
	{
		temp = ft_strdup(full);
		full = ft_strjoin(temp, line);
		line = get_next_line(fd);
	}
	map = ft_split(full, '\n');
	free(line);
	close(fd);
	return (map);
}

void	display_tile(t_game *game, int i, int j, int p)
{
	if (p == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->wall,
			j * TILE_SIZE, i * TILE_SIZE);
	else if (p == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->ground,
			j * TILE_SIZE, i * TILE_SIZE);
	else if (p == 2)
		mlx_put_image_to_window(game->mlx, game->win, game->player,
			j * TILE_SIZE, i * TILE_SIZE);
	else if (p == 3)
		mlx_put_image_to_window(game->mlx, game->win,
			game->collectible, j * TILE_SIZE, i * TILE_SIZE);
	else if (p == 4)
		mlx_put_image_to_window(game->mlx, game->win, game->exit,
			j * TILE_SIZE, i * TILE_SIZE);
}

void	display_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (j < (int)ft_strlen(game->map[i]))
		{
			if (game->map[i][j] == 49)
				display_tile(game, i, j, 0);
			else if (game->map[i][j] == 48)
				display_tile(game, i, j, 1);
			else if (game->map[i][j] == 80)
				display_tile(game, i, j, 2);
			else if (game->map[i][j] == 67)
				display_tile(game, i, j, 3);
			else if (game->map[i][j] == 69)
				display_tile(game, i, j, 4);
			j++;
		}
		i++;
	}
}
