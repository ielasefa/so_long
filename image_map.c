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
               mlx_put_image_to_window(game->mlx, game->win, game->img_hait, x * 50, y * 50);
           else if (game->map[y][x] == '0')
               mlx_put_image_to_window(game->mlx, game->win, game->img_ard, x * 50, y * 50);
           else if (game->map[y][x] == 'P')
               mlx_put_image_to_window(game->mlx, game->win, game->img_ard, x * 50, y * 50);
           else if (game->map[y][x] == 'E')
               mlx_put_image_to_window(game->mlx, game->win, game->img_ard, x * 50, y * 50);
           else if (game->map[y][x] == 'C')
               mlx_put_image_to_window(game->mlx, game->win, game->img_coin, x * 50, y * 50);
           x++;
       }
       y++;
   }
   mlx_put_image_to_window(game->mlx, game->win, game->img_player, game->player_x * 50, game->player_y * 50);
}


