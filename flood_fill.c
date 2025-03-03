/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:49:26 by iel-asef          #+#    #+#             */
/*   Updated: 2025/02/28 15:49:32 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_map(t_vars *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		i++;
	game->copy_map = malloc(sizeof(char *) * (i + 1));
	if (!game->copy_map)
		return ;
	i = 0;
	while (game->map[i])
	{
		game->copy_map[i] = ft_strdup(game->map[i]);
		if (!game->copy_map[i])
		{
			while (i > 0)
				free(game->copy_map[--i]);
			free(game->copy_map);
			return ;
		}
		i++;
	}
	game->copy_map[i] = NULL;
}

void	flood_fill(t_vars *game, int x, int y, int *exit, int *player,
		int *total_coin)
{
	if (x < 0 || y < 0 || !game->copy_map[y] || !game->copy_map[y][x])
		return ;
	if (game->copy_map[y][x] == '1' || game->copy_map[y][x] == 'V')
		return ;
	if (game->copy_map[y][x] == 'C')
	{
		(*total_coin)++;
	}
	if (game->copy_map[y][x] == 'E')
		(*exit)++;
	if (game->copy_map[y][x] == 'P')
		(*player)++;
	game->copy_map[y][x] = 'V';
	flood_fill(game, x + 1, y, exit, player, total_coin);
	flood_fill(game, x, y + 1, exit, player, total_coin);
	flood_fill(game, x - 1, y, exit, player, total_coin);
	flood_fill(game, x, y - 1, exit, player, total_coin);
}

void	find_enemy_f(t_vars *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->copy_map[y])
	{
		x = 0;
		while (game->copy_map[y][x])
		{
			if (game->copy_map[y][x] == 'H')
			{
				game->player_x_f = x;
				game->player_y_f = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	validate_flood_fill(t_vars *game)
{
	int	exit;
	int	player;
	int	total_coin;
	int	i;

	i = 0;
	total_coin = 0;
	exit = 0;
	player = 0;
	copy_map(game);
	find_enemy_f(game);
	cont_coin(game);
	if (!game->copy_map)
		return (0);
	flood_fill(game, game->player_x_f, game->player_y_f, &exit, &player,
		&total_coin);
	while (game->copy_map[i])
		free(game->copy_map[i++]);
	free(game->copy_map);
	if (exit == 1 && player == 1 && game->word_coin == total_coin)
		return (1);
	return (0);
}
