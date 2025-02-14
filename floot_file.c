#include "so_long.h"

void copy_map(t_vars *game)
{
    int i;
    int j;
    
    i = 0;
    while (game->map[i])
        i++;
    
    game->copy_map = malloc(sizeof(char *) * (i + 1));
    if (!game->copy_map)
        return;
    i = 0;
    while (game->map[i])
    {
        game->copy_map[i] = strdup(game->map[i]);
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

void flood_fill(t_vars *game, int x, int y, int *valid)
{
    if (x < 0 || y < 0 || !game->copy_map[y] || !game->copy_map[y][x])
        return;
    
    if (game->copy_map[y][x] == '1' || game->copy_map[y][x] == 'V')
        return;
    
    if (game->copy_map[y][x] == 'C')
    {
        (*valid)++;
        game->word_coin++;
    }
    if (game->copy_map[y][x] == 'E')
        (*valid)++;
    
    game->copy_map[y][x] = 'V';
    
    flood_fill(game, x + 1, y, valid);
    flood_fill(game, x - 1, y, valid);
    flood_fill(game, x, y + 1, valid);
    flood_fill(game, x, y - 1, valid);
}

int validate_flood_fill(t_vars *game)
{
    int valid;
    
    valid = 0;
    game->word_coin = 0;
    
    copy_map(game);
    if (!game->copy_map)
        return (0);
        
    flood_fill(game, game->player_x, game->player_y, &valid);
    
    int i = 0;
    while (game->copy_map[i])
        free(game->copy_map[i++]);
    free(game->copy_map);
    
    return (valid == game->total_collectibles + 1);
}