#include "so_long.h"

void ft_exit(t_vars *game)
{
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    
    ft_free_map(game);
    
    exit(0);
}

void ft_free_map(t_vars *game)
{
    int i = 0;
    
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

int close_window(t_vars *game)
{
    ft_exit(game);
    return (0);
}