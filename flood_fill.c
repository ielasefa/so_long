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

#include "ft_printf/ft_printf.h"
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

void	flood_fill(t_vars *game, int x, int y, t_verification *ver)
{
	if (x < 0 || y < 0 || !game->copy_map[y] || !game->copy_map[y][x])
		return ;
	if (game->copy_map[y][x] == '1' || game->copy_map[y][x] == 'V')
		return ;
	if (game->copy_map[y][x] == 'C')
		ver->total_coin_f++;
	if (game->copy_map[y][x] == 'E')
		ver->exit_f++;
	if (game->copy_map[y][x] == 'P')
		ver->player_f++;
	game->copy_map[y][x] = 'V';
	flood_fill(game, x + 1, y, ver);
	flood_fill(game, x, y + 1, ver);
	flood_fill(game, x - 1, y, ver);
	flood_fill(game, x, y - 1, ver);
}

void	find_player_f(t_vars *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->copy_map[y])
	{
		x = 0;
		while (game->copy_map[y][x])
		{
			if (game->copy_map[y][x] == 'P')
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

int	validate_flood_fill(t_vars *game, t_verification *ver)
{
	int	i;

	i = 0;
	ver->total_coin_f = 0;
	ver->exit_f = 0;
	ver->player_f = 0;
	copy_map(game);
	find_player_f(game);
	cont_coin(game);
	if (!game->copy_map)
		return (0);
	flood_fill(game, game->player_x_f, game->player_y_f, ver);
	while (game->copy_map[i])
		free(game->copy_map[i++]);
	free(game->copy_map);
	if (ver->exit_f == 1 && ver->player_f == 1
		&& game->word_coin == ver->total_coin_f)
		return (1);
	return (0);
}
