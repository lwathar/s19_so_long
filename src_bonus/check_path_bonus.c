/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lowathar <lowathar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:14:42 by lowathar          #+#    #+#             */
/*   Updated: 2023/03/24 13:22:30 by lowathar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_floodfill(t_map *backupdata, int x, int y)
{
	if (backupdata->full[y][x] == '1')
		return ;
	else if (backupdata->full[y][x] == 'B')
		return ;
	else if (backupdata->full[y][x] == 'C')
	{
		backupdata->full[y][x] = '1';
		backupdata->coins++;
	}
	else if (backupdata->full[y][x] == 'E')
	{
		backupdata->full[y][x] = '1';
		backupdata->exit++;
		return ;
	}
	backupdata->full[y][x] = '1';
	ft_floodfill(backupdata, x, (y + 1));
	ft_floodfill(backupdata, x, (y - 1));
	ft_floodfill(backupdata, (x + 1), y);
	ft_floodfill(backupdata, (x - 1), y);
}

void	ft_check_path(t_game *game)
{
	t_map	*backupdata;
	int		i;
	
	backupdata = malloc(sizeof(t_map));
	backupdata->coins = 0;
	backupdata->exit = 0;
	backupdata->full = game->map.full;
	ft_floodfill(backupdata, game->map.player.x, game->map.player.y);
	if (backupdata->coins != game->map.coins)
	{
		free(backupdata);
		ft_error_msg("Error path. Some coins are not accessible!", game);
	}
	else if (backupdata->exit != 1)
	{
		free(backupdata);
		ft_error_msg("Error path. The Exit is not accessible!", game);
	}
	i = 0;
	while (i < game->map.rows)
		free((backupdata->full[i++]));
	free(backupdata->full);
	free(backupdata);
}
