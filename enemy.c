#include "so_long"

void  enemy_position(t_vars *game)
{
    int x;
    int y;

    y = 0;
    while(game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if(game->map[y][x] == 'H')
            {
                game->enemy_x = x;
                game->enemy_y = y;
                return;
            }
            y++;
        }
        y++;
    }
}

void  animation(t_vars *game)
{
  c

}