/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 03:42:19 by iel-asef          #+#    #+#             */
/*   Updated: 2025/03/07 03:42:32 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "so_long.h"

int	update_animation_frame(t_vars *game)
{
	static int	count = 0;

	count++;
	if (count % 3000 == 0)
	{
		game->current_frame = (game->current_frame + 1) % 5;
		return (1);
	}
	return (0);
}

void	render_collectibles_animation(t_vars *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C'
				&& game->animation[game->current_frame] != NULL)
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->animation[game->current_frame], x * TILE_SIZE, y
					* TILE_SIZE);
			}
			x++;
		}
		y++;
	}
}

int	animation_loop(t_vars *game)
{
	if (update_animation_frame(game))
	{
		render_collectibles_animation(game);
	}
	return (0);
}

void	animation_image(t_vars *game)
{
	int	width;
	int	height;

	game->animation[0] = mlx_xpm_file_to_image(game->mlx, "assets/001.xpm",
			&width, &height);
	game->animation[1] = mlx_xpm_file_to_image(game->mlx, "assets/02.xpm",
			&width, &height);
	game->animation[2] = mlx_xpm_file_to_image(game->mlx, "assets/03.xpm",
			&width, &height);
	game->animation[3] = mlx_xpm_file_to_image(game->mlx, "assets/04.xpm",
			&width, &height);
	game->animation[4] = mlx_xpm_file_to_image(game->mlx, "assets/05.xpm",
			&width, &height);
	if (!game->animation[0] || !game->animation[1] || !game->animation[2]
		|| !game->animation[3] || !game->animation[4])
	{
		ft_printf("Error: animation images\n");
		ft_exit(game);
		return ;
	}
}
