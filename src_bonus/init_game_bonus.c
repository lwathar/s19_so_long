/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:29:40 by lowathar          #+#    #+#             */
/*   Updated: 2023/03/21 14:41:44 by lowathar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_vars(t_game *game)
{
	game->map.coins = 0;
	game->map.exit = 0;
	game->map.players = 0;
	game->mvt = 0;
	game->map.columns = ft_strlen(game->map.full[0]);
	game->player_sprite = RIGHT;
}

void	ft_init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		ft_error_msg("Cannot find mlx pointer", game);
	game->win = mlx_new_window(game->mlx, \
	game->map.columns * 32, game->map.rows * 32, "so_long");
	if (game->win == NULL)
	{
		free(game->mlx);
		ft_error_msg("Cannot create the window", game);
	}
	ft_init_sprites(game);
}

void	ft_init_sprites(t_game *game)
{
	game->wall = ft_new_sprite(game->mlx, WALL_XPM, game);
	game->floor = ft_new_sprite(game->mlx, FLOOR_XPM, game);
	game->coins = ft_new_sprite(game->mlx, COINS_XPM, game);
	game->open_exit = ft_new_sprite(game->mlx, OPEN_EXIT_XPM, game);
	game->closed_exit = ft_new_sprite(game->mlx, CLOSED_EXIT_XPM, game);
	game->player_front = ft_new_sprite(game->mlx, PLAYER_FRONT_XPM, game);
	game->player_back = ft_new_sprite(game->mlx, PLAYER_BACK_XPM, game);
	game->player_left = ft_new_sprite(game->mlx, PLAYER_LEFT_XPM, game);
	game->player_right = ft_new_sprite(game->mlx, PLAYER_RIGHT_XPM, game);
	game->boo = ft_new_sprite(game->mlx, BOO_XPM, game);
}

t_image	ft_new_sprite(void *mlx, char *path, t_game *game)
{
	t_image	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
		ft_error_msg("Cannot find a sprite. Does it exist?", game);
	return (sprite);
}
