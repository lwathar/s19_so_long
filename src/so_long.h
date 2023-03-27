/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:53:47 by lowathar          #+#    #+#             */
/*   Updated: 2023/03/21 11:49:22 by lowathar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define GREEN				"\033[0;32m"
# define RED 				"\033[1;31m"
# define GREY 				"\033[0;90m"
# define CYAN				"\033[1;96m"
# define RESET 				"\033[0m"

# define WALL				'1'
# define FLOOR 				'0'
# define COINS  			'C'
# define PLAYER				'P'
# define MAP_EXIT 		 	'E'

# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2

# define KEY_UP  			126
# define KEY_LEFT  			123
# define KEY_RIGHT 			124
# define KEY_DOWN  			125

# define KEY_Q				12
# define KEY_ESC  			53

# define WALL_XPM			"Sprites/wall.xpm"
# define FLOOR_XPM			"Sprites/floor.xpm"
# define COINS_XPM			"Sprites/coins.xpm"
# define OPEN_EXIT_XPM		"Sprites/open-exit.xpm"
# define CLOSED_EXIT_XPM	"Sprites/closed-exit.xpm"
# define PLAYER_FRONT_XPM	"Sprites/player-front.xpm"
# define PLAYER_BACK_XPM	"Sprites/player-back.xpm"
# define PLAYER_LEFT_XPM	"Sprites/player-left.xpm"
# define PLAYER_RIGHT_XPM	"Sprites/player-right.xpm"

# define FRONT				1
# define LEFT				2
# define RIGHT				3
# define BACK				4


typedef enum e_bool
{
	false,
	true
}		t_bool;

typedef struct s_pos
{
	int x;
	int y;
}		t_pos;

typedef struct s_image
{ 
	void	*xpm_ptr;
	int		x;
	int		y;
}			t_image;

typedef struct s_map
{
	char	**full;
	int		rows;
	int		columns;
	int		coins;
	int		exit;
	int		players;
	t_pos	player;
}			t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			mvt;
	int			player_sprite;
	t_map		map;
	t_bool		map_alloc;
	t_image		wall;
	t_image		floor;
	t_image		coins;
	t_image		open_exit;
	t_image		closed_exit;
	t_image		player_front;
	t_image		player_left;
	t_image		player_right;
	t_image		player_back;
	
}				t_game;

// check_cmd.c

void	ft_check_cmd_line(int argc, char **argv, t_game *game);
void	ft_init_map(t_game *game, char *argv);
void	ft_check_for_empty_line(char *map, t_game *game);

// init_game.c

void	ft_init_vars(t_game *game);
void	ft_init_mlx(t_game *game);
void	ft_init_sprites(t_game *game);
t_image	ft_new_sprite(void *mlx, char *path, t_game *game);

// check_map.c

void	ft_check_map(t_game *game);
void	ft_check_rows(t_game *game);
void	ft_check_columns(t_game *game);
void	ft_count_map_parameters(t_game *game);
void	ft_verify_map_parameters(t_game *game);

// map_to_image.c

int		ft_map_to_image(t_game *game);
void	ft_find_sprite(t_game *game, int y, int x);
void	ft_render_player(t_game *game, int y, int x);
void	ft_render_sprite(t_game *game, t_image sprite, int line, int column);
void	ft_print_mvt(t_game *game);

// key_input.c

int		ft_key_input(int key, t_game *game);
void	ft_player_move(t_game *game, int new_y, int new_x, int p_sprite);

// game_end.c

int		ft_you_win(t_game *game);
int		ft_close_game(t_game *game);
int		ft_error_msg(char *message, t_game *game);

// check_path.c

void	ft_check_path(t_game *game);
void	ft_floodfill(t_map *backupdata, int x, int y);

// utils.c

char	*ft_strappend(char **s1, const char *s2);
void	ft_free_map(t_game *game);
void	ft_free_memory(t_game *game);
void	ft_destroy_images(t_game *game);

#endif