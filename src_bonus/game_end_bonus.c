/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:19:40 by lowathar          #+#    #+#             */
/*   Updated: 2023/03/28 11:51:57 by lowathar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_you_win(t_game *game)
{
	ft_printf(CYAN"\n			Movements: %d\n"RESET, ++game->mvt);
	ft_free_memory(game);
	ft_printf(GREEN"\n\
██████████████████████████████████████████████████████████████████\n\
██                                                              ██\n\
██  ███  ███  ██████  ██    ██     ██      ██ ██ ██    ██   ██  ██\n\
██   ██  ██  ██    ██ ██    ██     ██      ██ ██ ███   ██   ██  ██\n\
██    ████   █      █ ██    ██     ██  ██  ██ ██ ██ ██ ██   ██  ██\n\
██     ██    ██    ██ ██    ██     ██ ████ ██ ██ ██  ████       ██\n\
██     ██     ██████    ████        ███  ███  ██ ██   ███   ██  ██\n\
██                                                              ██\n\
██████████████████████████████████████████████████████████████████\n\n\
"RESET);
	exit (EXIT_FAILURE);
}

int	ft_close_game(t_game *game)
{
	ft_printf(CYAN"Movements: %d\n"RESET, game->mvt);
	ft_free_memory(game);
	ft_printf(GREY"CLOSED\n"RESET);
	exit (EXIT_FAILURE);
}

int	ft_error_msg(char *message, t_game *game)
{
	if (game->map_alloc == true)
		ft_free_map(game);
	free(game);
	ft_printf(RED"Error\n"GREY"%s\n"RESET, message);
	exit (EXIT_FAILURE);
}

void	ft_free_memory(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
}

void	ft_destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall.xpm_ptr);
	mlx_destroy_image(game->mlx, game->floor.xpm_ptr);
	mlx_destroy_image(game->mlx, game->coins.xpm_ptr);
	mlx_destroy_image(game->mlx, game->player_front.xpm_ptr);
	mlx_destroy_image(game->mlx, game->player_left.xpm_ptr);
	mlx_destroy_image(game->mlx, game->player_right.xpm_ptr);
	mlx_destroy_image(game->mlx, game->player_back.xpm_ptr);
	mlx_destroy_image(game->mlx, game->closed_exit.xpm_ptr);
	mlx_destroy_image(game->mlx, game->open_exit.xpm_ptr);
	mlx_destroy_image(game->mlx, game->boo.xpm_ptr);
}
