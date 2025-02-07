#include "so_long.h"

void render_map(t_vars *game)
{
   int x;
   int y;
   char *move;

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
               mlx_put_image_to_window(game->mlx, game->win, game->img_home, x * TILE_SIZE, y * TILE_SIZE);
           else if (game->map[y][x] == 'C')
               mlx_put_image_to_window(game->mlx, game->win, game->img_coin, x * TILE_SIZE, y * TILE_SIZE);
           else if (game->map[y][x] == 'H')
               mlx_put_image_to_window(game->mlx, game->win, game->img_l3zwa, x * TILE_SIZE, y * TILE_SIZE);
           x++;
       }
       y++;
    
   }
   mlx_put_image_to_window(game->mlx, game->win, game->img_player, game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
   move = ft_itoa(game->move_nb);
   if(move)
    {   
        mlx_string_put(game->mlx, game->win, 50, 50, 0x000000, "Move: ");
        mlx_string_put(game->mlx, game->win, 100, 50, 0x000000, move);
        free(move);
    }
}

void    cont_coin(t_vars *game)
{
    int x;
    int y;

    y = 0;
    while(game->map[y]) 
    {
        x = 0;
        while (game->map[y][x])
        {
            if(game->map[y][x] == 'C')
                game->word_coin++;
             x++;
        }
        y++;
    }
}

