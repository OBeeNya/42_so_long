/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:26:06 by baubigna          #+#    #+#             */
/*   Updated: 2022/02/09 09:12:11 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdarg.h>

# define BUFFER_SIZE 1
# define TILE_SIZE 50
# define WALL "assets/wall.xpm"
# define GROUND "assets/ground.xpm"
# define PLAYER "assets/player.xpm"
# define COLLECTIBLE "assets/collectible.xpm"
# define EXIT "assets/exit.xpm"

/* keycodes */
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_game
{
	int		p;
	int		e;
	int		collec;
	int		img_width;
	int		win_width;
	int		img_height;
	int		win_height;
	int		pos_x;
	int		pos_y;
	int		steps;
	void	*mlx;
	void	*win;
	void	*player;
	void	*collectible;
	void	*wall;
	void	*exit;
	void	*ground;
	void	*w;
	void	*a;
	void	*s;
	void	*d;
	char	**map;
}				t_game;

/* includes */
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
int		treat_str(char *s);
int		nb_len(int n);
int		treat_int(int n);
int		treat_ptr(unsigned long l);
int		treat_args(va_list args, const char c);
int		is_conv(const char c);
int		treat_unsint(unsigned int u);
int		treat_hexa(unsigned int h, int i);
int		treat_char(int c);
int		ft_printf(const char *s, ...);

/* map_checker */
int		get_nb_lines(char **map);
int		check_first_last(char *line);
int		check_middle(char *line);
int		check_width(char **map);
int		check_map(char **map);

/* map_creator */
int		check_filename(char *filename);
char	**create_map(char *map_path);
void	display_tile(t_game *game, int i, int j, int p);
void	display_map(t_game *game);

/* map_initializer */
int		initialize_collec(t_game *game);
void	get_window_size(t_game *game);
void	load_xpm(t_game *game);
void	load_map(t_game *game);

/* moves */
void	move_up(t_game *game);
void	move_left(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);

/* main */
int		exit_game(t_game *game);
int		hooking(int keycode, t_game *game);
int		errors(t_game *game, int ac, char **av);
int		main(int ac, char **av);

#endif
