/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:34:18 by iel-asef          #+#    #+#             */
/*   Updated: 2025/03/05 17:34:21 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_vars *game)
{
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_l3zwa)
		mlx_destroy_image(game->mlx, game->img_l3zwa);
	if (game->img_hait)
		mlx_destroy_image(game->mlx, game->img_hait);
	if (game->img_ard)
		mlx_destroy_image(game->mlx, game->img_ard);
	if (game->img_home)
		mlx_destroy_image(game->mlx, game->img_home);
	if (game->img_coin)
		mlx_destroy_image(game->mlx, game->img_coin);
	free_animation(game);
	ft_free_map(game);
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
}

void	ft_free_map(t_vars *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
}
