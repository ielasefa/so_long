/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 03:36:54 by iel-asef          #+#    #+#             */
/*   Updated: 2025/03/07 03:37:05 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "so_long.h"

int	create_window(t_vars *game)
{
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE, game->height
			* TILE_SIZE, "So Long");
	if (!game->win)
	{
		ft_printf("Error\nin win\n");
		ft_exit(game);
		return (0);
	}
	return (1);
}

int	load_images(t_vars *game, int *width, int *height)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx, "assets/011.xpm", width,
			height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm",
			width, height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", width,
			height);
	game->img_home = mlx_xpm_file_to_image(game->mlx, "assets/05.xpm", width,
			height);
	game->img_coin = mlx_xpm_file_to_image(game->mlx, "assets/02.xpm", width,
			height);
	if (!game->img_player || !game->img_floor || !game->img_wall
		|| !game->img_coin || !game->img_home)
	{
		ft_printf("Error\nUnable to load some images\n");
		ft_exit(game);
		return (0);
	}
	return (1);
}

int	init_game(t_vars *game, t_verification *ver, int fd)
{
	game->map = get_maps(fd);
	close(fd);
	if (!game->map)
	{
		ft_printf("Error\ninvalide map\n");
		return (0);
	}
	if (!verification_map(game, ver))
	{
		ft_free_map(game);
		return (0);
	}
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error\nin init mlx \n");
		ft_free_map(game);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_vars			game;
	t_verification	ver;
	int				width;
	int				height;
	int				fd;

	game = (t_vars){0};
	if (ac != 2)
	{
		ft_printf("Error\nYou must provide exactly one argument\n");
		return (1);
	}
	fd = open_map(av[1]);
	if (fd == -1)
		return (1);
	if (!init_game(&game, &ver, fd) || !create_window(&game))
		return (1);
	if (!load_images(&game, &width, &height))
		return (1);
	render_map(&game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
