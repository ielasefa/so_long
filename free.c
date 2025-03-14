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
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_coin)
		mlx_destroy_image(game->mlx, game->img_coin);
	if (game->img_home)
		mlx_destroy_image(game->mlx, game->img_home);
		//free_animation(game);
	ft_free_map(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
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
