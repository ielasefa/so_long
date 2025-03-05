/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:18:08 by iel-asef          #+#    #+#             */
/*   Updated: 2025/02/13 19:18:10 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf/ft_printf.h"

int	handle_key(int keycode, void *param)
{
	t_vars *game;

	game = (t_vars *)param;
	if ((keycode == 119 || keycode == 65362) && game->map[game->player_y
		- 1][game->player_x] != '1')
		move_player(game, -1, 0);
	else if ((keycode == 115 || keycode == 65364) && game->map[game->player_y
		+ 1][game->player_x] != '1')
		move_player(game, 1, 0);
	else if ((keycode == 97 || keycode == 65361)
		&& game->map[game->player_y][game->player_x - 1] != '1')
		move_player(game, 0, -1);
	else if ((keycode == 100 || keycode == 65363)
		&& game->map[game->player_y][game->player_x + 1] != '1')
		move_player(game, 0, 1);
	else if (keycode == 65307)
	{
		ft_exit(game);
		exit(0);
	}
	return (0);
}


void	move_player(t_vars *game, int y_move, int x_move)
{
	game->move_nb++;
	ft_printf("%d\n", game->move_nb);
	game->player_y += y_move;
	game->player_x += x_move;
	player_coin(game);
	render_map(game);
}

void	player_coin(t_vars *game)
{
	find_home(game);
	if (game->map[game->player_y][game->player_x] == 'C')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->cont_coin++;
		if (game->cont_coin == game->word_coin)
		{
			game->map[game->home_y][game->home_x] = 'E';
			mlx_put_image_to_window(game->mlx, game->win, game->img_home,
				game->home_x * TILE_SIZE, game->home_y * TILE_SIZE);
		}
	}
	if (game->map[game->player_y][game->player_x] == 'E'
		&& game->cont_coin == game->word_coin)
	{
		ft_printf("---------------YOU WIN--------------------");
		ft_exit(game);
		exit(0);
	}
	if (game->map[game->player_y][game->player_x] == 'H')
	{
		ft_printf("----------Game Over-------------------");
		ft_exit(game);
		exit(0);
	}
}

void	cont_coin(t_vars *game)
{
	int x;
	int y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
				game->word_coin++;
			x++;
		}
		y++;
	}
}