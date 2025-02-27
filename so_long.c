/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:18:19 by iel-asef          #+#    #+#             */
/*   Updated: 2025/02/13 19:18:21 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_maps(int fd)
{
	char	*line;
	char	*all_lines;
	char	**map_array;
	char	*temp;

	all_lines = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (all_lines == NULL)
			all_lines = ft_strdup(line);
		else
		{
			temp = ft_strjoin(all_lines, line);
			free(all_lines);
			all_lines = temp;
		}
		free(line);
	}
	if (!all_lines)
		return (NULL);
	map_array = ft_split(all_lines, '\n');
	free(all_lines);
	return (map_array);
}

int	open_map(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: l fichier ma kaynch ola ma kayt7lch\n");
		return (-1);
	}
	return (fd);
}

int	init_game(t_vars *game, int fd)
{
	game->map = get_maps(fd);
	close(fd);
	if (!game->map)
	{
		printf("Error: invalide map\n");
		return (0);
	}
	if (!verification_map(game))
	{
    	ft_free_map(game);
    	return (0);
	}
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		printf("Error\n: invalide mlx \n");
		ft_free_map(game);
		return (0);
	}
	return (1);
}

int	create_window(t_vars *game)
{
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE, game->height
			* TILE_SIZE, "So Long");
	if (!game->win)
	{
		printf("Error:\n in \n");
		ft_exit(game);
		return (0);
	}
	return (1);
}

int	load_images(t_vars *game, int *width, int *height)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm",
			width, height);
	game->img_l3zwa = mlx_xpm_file_to_image(game->mlx, "assets/cjj.xpm", width,
			height);
	game->img_hait = mlx_xpm_file_to_image(game->mlx, "assets/haiiiit.xpm",
			width, height);
	game->img_ard = mlx_xpm_file_to_image(game->mlx, "assets/lard.xpm", width,
			height);
	game->img_coin = mlx_xpm_file_to_image(game->mlx, "assets/icon_heart.xpm",
			width, height);
	game->img_home = mlx_xpm_file_to_image(game->mlx, "assets/home.xpm", width,
			height);
if (!game->img_player || !game->img_l3zwa || !game->img_hait
    || !game->img_ard || !game->img_coin || !game->img_home)
{
    printf("Error: ma qdertch nloadi l images\n");
	ft_exit(game);
    return (0);
}

	return (1);
}

int	main(int ac, char **av)
{
	t_vars	game;
	int		width;
	int		height;
	int		fd;

	game = (t_vars){0};
	if (ac != 2)
	{
		printf("Error: khssek tdir argument wahd\n");
		return (1);
	}
	fd = open_map(av[1]);
	if (fd == -1)
		return (1);
	if (!init_game(&game, fd))
		return (1);
	if (!create_window(&game))
		return (1);
	if (!load_images(&game, &width, &height))
		return (1);
	srand(time(NULL));
	animation_image(&game);
	game.current_frame = 0;
	cont_coin(&game);
	find_enemy(&game);
	game.dir = 1;
	game.enemy_speed = 400000;
	render_map(&game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
