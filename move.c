#include "so_long.h"

int handle_key(int keycode, void *param)
{
    t_vars *game = (t_vars *)param;

    if (keycode ==  || keycode ==  )
        playr++;
    if (keycode ==  || keycode ==  )
        playr--;
    if (keycode ==  || keycode ==  )
        playr++;
    if (keycode ==  || keycode ==  )
        playr--;
    if (keycode == ESC_KEY)
    {
        mlx_destroy_window(game->mlx, game->win);
        exit(0);
    }
    return 0;
}