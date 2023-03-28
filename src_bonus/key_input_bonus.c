/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:01:22 by lowathar          #+#    #+#             */
/*   Updated: 2023/03/28 11:52:27 by lowathar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_key_input(int key, t_game *game)
{
	if (key == KEY_UP || key == KEY_W)
		ft_player_move(game, game->map.player.y - 1, game->map.player.x, BACK);
	if (key == KEY_LEFT || key == KEY_A)
		ft_player_move(game, game->map.player.y, game->map.player.x - 1, LEFT);
	if (key == KEY_RIGHT || key == KEY_D)
		ft_player_move(game, game->map.player.y, game->map.player.x + 1, RIGHT);
	if (key == KEY_DOWN || key == KEY_S)
		ft_player_move(game, game->map.player.y + 1, game->map.player.x, FRONT);
	if (key == KEY_Q || key == KEY_ESC)
		ft_close_game(game);
	return (0);
}

void	ft_player_move(t_game *game, int new_y, int new_x, int p_sprite)
{
	int	last_x;
	int	last_y;

	game->player_sprite = p_sprite;
	last_x = game->map.player.x;
	last_y = game->map.player.y;
	if (game->map.full[new_y][new_x] == BOO)
		ft_lose(game);
	if (game->map.full[new_y][new_x] == MAP_EXIT && game->map.coins == 0)
		ft_you_win(game);
	else if ((game->map.full[new_y][new_x] == FLOOR) \
	|| (game->map.full[new_y][new_x] == COINS))
	{
		game->map.full[last_y][last_x] = FLOOR;
		if (game->map.full[new_y][new_x] == COINS)
			game->map.coins--;
		game->map.player.x = new_x;
		game->map.player.y = new_y;
		game->map.full[new_y][new_x] = PLAYER;
		game->mvt++;
		ft_map_to_image(game);
	}
}

int	ft_lose(t_game *game)
{
	ft_printf(CYAN"\n			Movements: %d\n"RESET, ++game->mvt);
	ft_printf(RED"\n\
█████████████████████████████████████████████████████████████████████\n\
██                                                                 ██\n\
██  ███  ███  ██████  ██    ██     ██      ██████   ██████ ██████  ██\n\
██   ██  ██  ██    ██ ██    ██     ██     ██    ██ ██      ██      ██\n\
██    ████   █      █ ██    ██     ██     █      █   ████  █████   ██\n\
██     ██    ██    ██ ██    ██     ██     ██    ██      ██ ██      ██\n\
██     ██     ██████    ████       ██████  ██████  ██████  ██████  ██\n\
██                                                                 ██\n\
█████████████████████████████████████████████████████████████████████\n\n\
"RESET);
	ft_free_memory(game);
	exit (EXIT_FAILURE);
}
