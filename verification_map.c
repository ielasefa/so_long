#include "so_long.h"


/*
static int	ft_count_chars(char c, char *str)
{
   int	count;

   count = 0;
   while (*str)
   {
   	if (*str == c)
   		count++;
   	str++;
   }
   return (count);
}*/

static int	ft_check_map_chars(t_vars *game, int *collect, int *ex, int *play)
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
   			(*ex)++;
   		else if (game->map[x][y] == 'P')
   		{
   			(*play)++;
   			game->player_x = y;
   			game->player_y = x;
   		}
   		else if (game->map[x][y] == 'C')
   			(*collect)++;
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
   	if (game->map[0][x] != '1' || 
   		game->map[game->height - 1][x] != '1')
   		return (0);
   }
   y = -1;
   while (++y < game->height)
   {
   	if (game->map[y][0] != '1' || 
   		game->map[y][game->width - 1] != '1')
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

int	verification_map(t_vars *game)
{
   int	collect;
   int	exit;
   int	player;

   collect = 0;
   exit = 0;
   player = 0;
   if (!game->map || !game->map[0])
   	return (0);
   game->player_x = -1;
   game->player_y = -1;
   if (!ft_check_map_chars(game, &collect, &exit, &player))
   	return (0);
   if (player != 1 || exit != 1 || collect < 1)
   	return (0);
   if (!ft_check_line(game) || !ft_check_borders(game))
   	return (0);
   return (1);
}