#include "so_long.h"

void copy_map(t_vars *game)
{
    int i;
    
    i = 0;
    while (game->map[i])
        i++;
    
    game->copy_map = malloc(sizeof(char *) * (i + 1));
    if (!game->copy_map)
        return;
    i = 0;
    while (game->map[i])
    {
        game->copy_map[i] = ft_strdup(game->map[i]);
        if (!game->copy_map[i])
        {
            while (i > 0)
                free(game->copy_map[--i]);
            free(game->copy_map);
            return;
        }
        i++;
    }
    game->copy_map[i] = NULL;
}
 
void flood_fill(t_vars *game, int x, int y, int *exit ,int *player ,int *total_coin)
{
    if (x < 0 || y < 0 || !game->copy_map[y] || !game->copy_map[y][x])
        return;
    
    if (game->copy_map[y][x] == '1' || game->copy_map[y][x] == 'V')
        return;
    
    if (game->copy_map[y][x] == 'C')
    {
        (*total_coin)++;
    }
    if (game->copy_map[y][x] == 'E' )
        (*exit)++;

    if (game->copy_map[y][x] == 'P' )
        (*player)++;

    game->copy_map[y][x] = 'V';
    
    flood_fill(game, x + 1, y, exit ,player ,total_coin);
    flood_fill(game, x, y + 1, exit ,player ,total_coin);
    flood_fill(game, x - 1, y, exit ,player ,total_coin);
    flood_fill(game, x, y - 1, exit ,player ,total_coin);
}

int validate_flood_fill(t_vars *game)
{
    int exit;
    int player;
    int total_coin;
    int i;
    
    i = 0;
    total_coin = 0;
    exit = 0;
    player = 0;
    copy_map(game);
    cont_coin(game);
    if (!game->copy_map)
        return (0);    
    flood_fill(game, game->player_x, game->player_y, &exit , &player ,&total_coin);
    
    while (game->copy_map[i])
        free(game->copy_map[i++]);
    free(game->copy_map);
    if (exit == 1  && player == 1  && game->word_coin == total_coin )
        return 1;
    return 0;    
}