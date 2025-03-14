/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:17:50 by iel-asef          #+#    #+#             */
/*   Updated: 2025/02/13 19:17:53 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "so_long.h"

void	render_tile(t_vars *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x
			* TILE_SIZE, y * TILE_SIZE);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x
			* TILE_SIZE, y * TILE_SIZE);
	
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'E')
	{
		if (game->cont_coin  == game->word_coin)
			mlx_put_image_to_window(game->mlx, game->win, game->img_home, x
			* TILE_SIZE, y * TILE_SIZE);
	}
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img_coin, x
			* TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_vars *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img_player,
		game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
}