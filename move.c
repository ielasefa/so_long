#include "so_long.h"

int handle_key(int keycode, void *param)
{
   t_vars *game = (t_vars *)param;
   
   if((keycode == 119 || keycode == 65362) 
       && game->map[game->player_y - 1][game->player_x] != '1')
   {
       game->move_nb++;
       printf("%d\n", game->move_nb);
       game->player_y--;
       player_coin(game);
       render_map(game);
   }
   if ((keycode == 115 || keycode == 65364)
       && game->map[game->player_y + 1][game->player_x] != '1')
   {
       game->move_nb++;
       printf("%d\n", game->move_nb);
       game->player_y++;
       player_coin(game);
       render_map(game);
   }
   if ((keycode == 97 || keycode == 65361) 
       && game->map[game->player_y][game->player_x - 1] != '1')
   {
       game->move_nb++;
       printf("%d\n", game->move_nb);
       game->player_x--;
       player_coin(game);
       render_map(game);
   }
   if ((keycode == 100 || keycode == 65363)
       && game->map[game->player_y][game->player_x + 1] != '1')
   {
       game->move_nb++;
       printf("%d\n", game->move_nb);
       game->player_x++;
       player_coin(game);
       render_map(game);
   }
   if (keycode == 65307)
   {
       mlx_destroy_window(game->mlx, game->win);
       exit(0);
   }
   return 0;
}

void find_player(t_vars *game)
 {
    int y; 
    int x;
    y = 0;
    while (game->map[y])
    {
        x = 0;
         while (game->map[y][x])
         {
            if (game->map[y][x] == 'P')
            {
                game->player_x = x;
                game->player_y = y;
                return;
            }
            x++;
        }
        y++;
    }
}

void player_coin(t_vars *game)
{
    if (game->map[game->player_y][game->player_x] == 'C')
    {
        game->map[game->player_y][game->player_x] = '0'; 
        game->cont_coin++;
    }
    if (game->map[game->player_y][game->player_x] == 'H')
        {
            printf("----------hwak l3aza-------------------");
            ft_free_map(game);
            mlx_destroy_window(game->mlx, game->win);
            exit(0);
        }
    if(game->cont_coin == game->word_coin 
             && game->map[game->player_y][game->player_x] == 'E')            
    {
        printf("---------------YOU WIN--------------------");
        mlx_destroy_window(game->mlx, game->win);
        exit(0);
    }
}