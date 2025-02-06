#include "so_long.h"

void render_map(t_vars *game)
{
   int x;
   int y;
   y = 0;
   while (game->map[y])
   {
       x = 0;
       while (game->map[y][x])
       {
           if (game->map[y][x] == '1')
               mlx_put_image_to_window(game->mlx, game->win, game->img_hait, x * TILE_SIZE, y * TILE_SIZE);
           else if (game->map[y][x] == '0')
               mlx_put_image_to_window(game->mlx, game->win, game->img_ard, x * TILE_SIZE, y * TILE_SIZE);
           else if (game->map[y][x] == 'P')
               mlx_put_image_to_window(game->mlx, game->win, game->img_ard, x * TILE_SIZE, y * TILE_SIZE);
           else if (game->map[y][x] == 'E')
               mlx_put_image_to_window(game->mlx, game->win, game->img_l3zwa, x * TILE_SIZE, y * TILE_SIZE);
           else if (game->map[y][x] == 'C')
               mlx_put_image_to_window(game->mlx, game->win, game->img_coin, x * TILE_SIZE, y * TILE_SIZE);
           x++;
       }
       y++;
   }
   mlx_put_image_to_window(game->mlx, game->win, game->img_player, game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
}

void    cont_coin(t_vars *game)
{
    game->word_coin;
    
    if(game->)
}
