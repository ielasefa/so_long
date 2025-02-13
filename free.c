#include "so_long.h"

void free_images(t_vars *game)
{
    if (game->img_player)
        mlx_destroy_image(game->mlx, game->img_player);
    if (game->img_l3zwa)
        mlx_destroy_image(game->mlx, game->img_l3zwa);
    if (game->img_hait)
        mlx_destroy_image(game->mlx, game->img_hait);
    if (game->img_ard)
        mlx_destroy_image(game->mlx, game->img_ard);
    if (game->img_coin)
        mlx_destroy_image(game->mlx, game->img_coin);
    if (game->img_home)
        mlx_destroy_image(game->mlx, game->img_home);
}

void free_animation(t_vars *game)
{
    int i = 0;
    while (i < 7)
    {
        if (game->animation[i])
            mlx_destroy_image(game->mlx, game->animation[i]);
        i++;
    }
}

void ft_free_map(t_vars *game)
{
    int y = 0;
    while (game->map[y])
    {
        free(game->map[y]);
        y++;
    }
    free(game->map);
}

void ft_exit(t_vars *game)
{
    free_images(game);      
    free_animation(game);    
    ft_free_map(game);      
    if (game->win)
        mlx_destroy_window(game->mlx, game->win); 
    exit(0);
}