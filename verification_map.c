/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:18:44 by iel-asef          #+#    #+#             */
/*   Updated: 2025/02/13 19:18:46 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "so_long.h"

static int	ft_check_map_chars(t_vars *game, t_verification *ver)
{
	int	x;
	int	y;

	x = -1;
	while (game->map[++x])
	{
		y = -1;
		while (game->map[x][++y])
		{
			if (game->map[x][y] == 'E')
				(ver->exit)++;
			else if (game->map[x][y] == 'P')
				handle_player(game, ver, x, y);
			else if (game->map[x][y] == 'C')
				(ver->collect)++;
			else if (game->map[x][y] != '1' && game->map[x][y] != '0')
				return (0);
		}
	}
	game->width = y;
	game->height = x;
	return (1);
}

static int	ft_check_borders(t_vars *game)
{
	int	x;
	int	y;

	x = -1;
	while (++x < game->width)
	{
		if (game->map[0][x] != '1' || game->map[game->height - 1][x] != '1')
			return (0);
	}
	y = -1;
	while (++y < game->height)
	{
		if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
			return (0);
	}
	return (1);
}

static int	ft_check_line(t_vars *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != (size_t)game->width)
			return (0);
		i++;
	}
	return (1);
}

int	verification_map(t_vars *game, t_verification *ver)
{
	ver->collect = 0;
	ver->exit = 0;
	ver->player = 0;
	if (!game->map || !game->map[0])
	{
		ft_printf("Error\n: Empty map\n");
		return (0);
	}
	if (!ft_check_map_chars(game, ver))
	{
		ft_printf("Error\n: Invalid characters found\n");
		return (0);
	}
	if (ver->player != 1 || ver->exit != 1 || ver->collect < 1)
	{
		ft_printf("Error\n: Wrong number of elements\n");
		return (0);
	}
	return (verification_map_2(game, ver));
}

int	verification_map_2(t_vars *game, t_verification *ver)
{
	if (!ft_check_line(game))
	{
		ft_printf("Error\n: Lines have different lengths\n");
		return (0);
	}
	if (!ft_check_borders(game))
	{
		ft_printf("Error\n: Map borders are not walls\n");
		return (0);
	}
	if (!validate_flood_fill(game, ver))
	{
		ft_printf("Error\n: Flood fill\n");
		return (0);
	}
	return (1);
}
