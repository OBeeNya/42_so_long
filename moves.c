/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 06:53:11 by baubigna          #+#    #+#             */
/*   Updated: 2022/02/12 16:55:08 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->pos_y - 1][game->pos_x] == '0'
			|| game->map[game->pos_y - 1][game->pos_x] == 'C')
	{
		if (game->map[game->pos_y - 1][game->pos_x] == 'C')
			game->collec--;
		game->map[game->pos_y - 1][game->pos_x] = 'P';
		game->map[game->pos_y][game->pos_x] = '0';
		game->pos_y--;
		game->steps++;
	}
	else if (game->map[game->pos_y - 1][game->pos_x] == 'E'
				&& game->collec == 0)
	{
		game->map[game->pos_y - 1][game->pos_x] = 'P';
		game->map[game->pos_y][game->pos_x] = '0';
		game->pos_y--;
		game->steps++;
		exit_game(game);
	}
	ft_printf("%d\n", game->steps);
	display_map(game);
}

void	move_left(t_game *game)
{
	if (game->map[game->pos_y][game->pos_x - 1] == '0'
			|| game->map[game->pos_y][game->pos_x - 1] == 'C')
	{
		if (game->map[game->pos_y][game->pos_x - 1] == 'C')
			game->collec--;
		game->map[game->pos_y][game->pos_x - 1] = 'P';
		game->map[game->pos_y][game->pos_x] = '0';
		game->pos_x--;
		game->steps++;
	}
	else if (game->map[game->pos_y][game->pos_x - 1] == 'E'
				&& game->collec == 0)
	{
		game->map[game->pos_y][game->pos_x - 1] = 'P';
		game->map[game->pos_y][game->pos_x] = '0';
		game->pos_x--;
		game->steps++;
		exit_game(game);
	}
	ft_printf("%d\n", game->steps);
	display_map(game);
}

void	move_down(t_game *game)
{
	if (game->map[game->pos_y + 1][game->pos_x] == '0'
			|| game->map[game->pos_y + 1][game->pos_x] == 'C')
	{
		if (game->map[game->pos_y + 1][game->pos_x] == 'C')
			game->collec--;
		game->map[game->pos_y + 1][game->pos_x] = 'P';
		game->map[game->pos_y][game->pos_x] = '0';
		game->pos_y++;
		game->steps++;
	}
	else if (game->map[game->pos_y + 1][game->pos_x] == 'E'
				&& game->collec == 0)
	{
		game->map[game->pos_y + 1][game->pos_x] = 'P';
		game->map[game->pos_y][game->pos_x] = '0';
		game->pos_y++;
		game->steps++;
		exit_game(game);
	}
	ft_printf("%d\n", game->steps);
	display_map(game);
}

void	move_right(t_game *game)
{
	if (game->map[game->pos_y][game->pos_x + 1] == '0'
			|| game->map[game->pos_y][game->pos_x + 1] == 'C')
	{
		if (game->map[game->pos_y][game->pos_x + 1] == 'C')
			game->collec--;
		game->map[game->pos_y][game->pos_x + 1] = 'P';
		game->map[game->pos_y][game->pos_x] = '0';
		game->pos_x++;
		game->steps++;
	}
	else if (game->map[game->pos_y][game->pos_x + 1] == 'E'
				&& game->collec == 0)
	{
		game->map[game->pos_y][game->pos_x + 1] = 'P';
		game->map[game->pos_y][game->pos_x] = '0';
		game->pos_x++;
		game->steps++;
		exit_game(game);
	}
	ft_printf("%d\n", game->steps);
	display_map(game);
}
