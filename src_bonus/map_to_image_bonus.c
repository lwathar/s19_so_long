/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_image_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:56:19 by lowathar          #+#    #+#             */
/*   Updated: 2023/03/27 11:35:47 by lowathar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_map_to_image(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			ft_find_sprite(game, y, x);
			x++;
		}
		y++;
	}
	ft_print_mvt(game);
	return (0);
}

void	ft_find_sprite(t_game *game, int y, int x)
{	
	char	parameter;

	parameter = game->map.full[y][x];
	if (parameter == WALL)
		ft_render_sprite (game, game->wall, y, x);
	else if (parameter == FLOOR)
		ft_render_sprite (game, game->floor, y, x);
	else if (parameter == COINS)
		ft_render_sprite (game, game->coins, y, x);
	else if (parameter == MAP_EXIT)
	{
		if (game->map.coins == 0)
			ft_render_sprite (game, game->open_exit, y, x);
		else
			ft_render_sprite (game, game->closed_exit, y, x);
	}
	else if (parameter == PLAYER)
		ft_render_player (game, y, x);
	else if (parameter == BOO)
		ft_render_sprite (game, game->boo, y, x);
}

void	ft_render_player(t_game *game, int y, int x)
{
	if (game->player_sprite == FRONT)
		ft_render_sprite (game, game->player_front, y, x);
	if (game->player_sprite == LEFT)
		ft_render_sprite (game, game->player_left, y, x);
	if (game->player_sprite == RIGHT)
		ft_render_sprite (game, game->player_right, y, x);
	if (game->player_sprite == BACK)
		ft_render_sprite (game, game->player_back, y, x);
}

void	ft_render_sprite(t_game *game, t_image sprite, int line, int column)
{
	mlx_put_image_to_window (game->mlx, game->win, \
	sprite.xpm_ptr, column * sprite.x, line * sprite.y);
}

void	ft_print_mvt(t_game *game)
{
	char	*mvt;
	char	*phrase;

	if (game->mvt > 0)
		ft_printf("Movements : %i\n", game->mvt);
	mvt = ft_itoa(game->mvt);
	phrase = ft_strjoin("Movements : ", mvt);
	mlx_string_put(game->mlx, game->win, 10, 5, 0x00FFFFFF, phrase);
	free(mvt);
	free(phrase);
}
