/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:53:50 by lowathar          #+#    #+#             */
/*   Updated: 2023/03/24 11:26:29 by lowathar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	ft_check_cmd_line(argc, argv, game);
	ft_init_map(game, argv[1]);
	ft_init_vars(game);
	ft_check_map(game);
	ft_check_path(game);
	ft_init_map(game, argv[1]);
	ft_init_mlx(game);
	ft_map_to_image(game);
	mlx_hook(game->win, 02, 0, ft_key_input, game);
	mlx_hook(game->win, 17, 2, ft_close_game, game);
	mlx_hook(game->win, 12, 15, ft_map_to_image, game);
	mlx_loop(game->mlx);
	ft_free_memory(game);
}
