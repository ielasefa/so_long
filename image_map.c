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
                mlx_put_image_to_window(game->mlx, game->win, game->animation[game->current_frame], x * TILE_SIZE, y * TILE_SIZE);
            else if (game->map[y][x] == 'H')
                mlx_put_image_to_window(game->mlx, game->win, game->img_l3zwa, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(game->mlx, game->win, game->img_player, game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
    move = ft_itoa(game->move_nb);
    if (move)
    {   
        mlx_string_put(game->mlx, game->win, 50, 50, 0x000000, "Move: ");
        mlx_string_put(game->mlx, game->win, 100, 50, 0x000000, move);
        free(move);
    }
}

void free_animation(t_vars *game)
{
    int i;
    
    i = 0;
    while (i < 7)
    {
        if (game->animation[i])
            mlx_destroy_image(game->mlx, game->animation[i]);
        i++;
    }
}

void animation_image(t_vars *game)
{
    int width;
    int height;

    game->animation[0] = mlx_xpm_file_to_image(game->mlx, "assets/coin1.xpm", &width, &height);
    game->animation[1] = mlx_xpm_file_to_image(game->mlx, "assets/coin2.xpm", &width, &height);
    game->animation[2] = mlx_xpm_file_to_image(game->mlx, "assets/coin3.xpm", &width, &height);
    game->animation[3] = mlx_xpm_file_to_image(game->mlx, "assets/coin4.xpm", &width, &height);
    game->animation[4] = mlx_xpm_file_to_image(game->mlx, "assets/coin5.xpm", &width, &height);
    game->animation[5] = mlx_xpm_file_to_image(game->mlx, "assets/coin6.xpm", &width, &height);
    game->animation[6] = mlx_xpm_file_to_image(game->mlx, "assets/coin7.xpm", &width, &height);

   if (!game->animation[0] || !game->animation[1] || !game->animation[2] || 
        !game->animation[4] || !game->animation[5] ||
        !game->animation[6])
    {
        printf("Error: animation images\n");
        ft_exit(game);
        return;
    }
}

int animation_loop(t_vars *game)
{
   static int count = 0;
   int x;
   int y;

   count++;
   if (count % 3000 == 0)
   {
       game->current_frame = (game->current_frame + 1) % 7;
       y = 0;
       while(game->map[y])
       {
           x = 0;
           while (game->map[y][x])
           {
               if(game->map[y][x] == 'C')
               {
                   mlx_put_image_to_window(game->mlx, game->win, 
                       game->animation[game->current_frame],
                       x * TILE_SIZE, y * TILE_SIZE);
               }
               x++;
           }
           y++;
       }
   }
   return (0);
}