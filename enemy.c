/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:16:19 by iel-asef          #+#    #+#             */
/*   Updated: 2025/02/13 19:20:33 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_enemy(t_vars *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'H')
			{
				game->enemy_x = x;
				game->enemy_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	move_enemy(t_vars *game)
{
	int	next_x;
	int	next_y;
	int	direction;

	next_x = game->enemy_x;
	next_y = game->enemy_y;
	direction = rand() % 4;
	if (direction == 0)
		next_x++;
	else if (direction == 1)
		next_x--;
	else if (direction == 2)
		next_y--;
	else if (direction == 3)
		next_y++;
	if (game->map[next_y][next_x] != '1' && game->map[next_y][next_x] != 'E'
		&& game->map[next_y][next_x] != 'C')
	{
		game->map[game->enemy_y][game->enemy_x] = '0';
		game->enemy_x = next_x;
		game->enemy_y = next_y;
		game->map[game->enemy_y][game->enemy_x] = 'H';
	}
}

int	game_loop(t_vars *game)
{
	static int	count = 0;

	count++;
	if (count % game->enemy_speed == 0)
	{
		move_enemy(game);
		render_map(game);
	}
	check_enemy_collision(game);
	animation_loop(game);
	return (0);
}

void	check_enemy_collision(t_vars *game)
{
	if (game->player_x == game->enemy_x && game->player_y == game->enemy_y)
	{
		printf("\nGame Over!\n");
		ft_exit(game);
	}
}
