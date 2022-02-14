/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initializer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:07:24 by baubigna          #+#    #+#             */
/*   Updated: 2022/02/09 07:06:15 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initialize_collec(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->p = 0;
	game->e = 0;
	game->collec = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 67)
				game->collec++;
			if (game->map[i][j] == 69)
				game->e++;
			if (game->map[i][j] == 80)
				game->p++;
			j++;
		}
		i++;
	}
	if (game->collec < 1 || game->e != 1 || game->p != 1)
		return (0);
	return (1);
}

void	get_window_size(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->win_width = ft_strlen(game->map[0]) * TILE_SIZE;
	game->win_height = get_nb_lines(game->map) * TILE_SIZE;
	game->steps = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->pos_x = x;
				game->pos_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	load_xpm(t_game *game)
{
	game->wall = mlx_xpm_file_to_image(game->mlx, WALL, &game->img_width,
			&game->img_height);
	game->ground = mlx_xpm_file_to_image(game->mlx, GROUND, &game->img_width,
			&game->img_height);
	game->player = mlx_xpm_file_to_image(game->mlx, PLAYER, &game->img_width,
			&game->img_height);
	game->collectible = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE,
			&game->img_width, &game->img_height);
	game->exit = mlx_xpm_file_to_image(game->mlx, EXIT, &game->img_width,
			&game->img_height);
}

void	load_map(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->ground,
		TILE_SIZE, TILE_SIZE);
}
