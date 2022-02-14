/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:25:22 by baubigna          #+#    #+#             */
/*   Updated: 2022/02/14 13:36:27 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	ft_printf("Number of steps taken: %d.\n", game->steps);
	exit (0);
}

int	hooking(int keycode, t_game *game)
{
	if (keycode == ESC)
		exit_game(game);
	else if (keycode == W)
		move_up(game);
	else if (keycode == A)
		move_left(game);
	else if (keycode == S)
		move_down(game);
	else if (keycode == D)
		move_right(game);
	return (0);
}

int	errors(t_game *game, int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("Error\nPlease give 2 arguments.\n");
		return (0);
	}
	if (!check_filename(av[1]))
	{
		ft_printf("Error\nPlease provide a valid map file.\n");
		return (0);
	}
	game->map = create_map(av[1]);
	if (!game->map)
	{
		ft_printf("Error\nPlease provide a valid map file.\n");
		return (0);
	}
	if (!check_map(game->map) || !initialize_collec(game))
	{
		ft_printf("Error\nPlease provide a valid map.\n");
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (!errors(&game, ac, av))
		return (0);
	get_window_size(&game);
	load_xpm(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.win_width, game.win_height,
			"so_long");
	display_map(&game);
	mlx_hook(game.win, 2, 1L << 0, hooking, &game);
	mlx_hook(game.win, 17, 0L, exit_game, &game);
	mlx_loop(game.mlx);
	free(&game);
	return (0);
}
