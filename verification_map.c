#include "so_long.h"

int verification_caractere(char **map, int *collection, int *exit, int *player)
{
    int x = 0;
    int y;

    while (map[x])
    {
        y = 0;
        while (map[x][y])
        {
            if (map[x][y] == 'E')
                (*exit)++;
            else if (map[x][y] == 'P')
                (*player)++;
            else if (map[x][y] == 'C')
                (*collection)++;
            else if (map[x][y] != '1' && map[x][y] != '0')
                return 0;
            y++;
        }
        x++;
    }
    return 1;
}

int verification_line(char **map)
{
    int len;
    int i; 
    
    i = 0;

    if (!map || !map[0]) 
        return 0;

    len = (int)ft_strlen(map[0]); 

    while (map[i])
    {
        if ((int)ft_strlen(map[i]) != len)  
            return 0;
        i++;
    }
    return 1;
}

int check_borders(char **map)
{
    int height = 0;
    int width;
    int x, y;
    
    while (map[height])
        height++;
    
    width = (int)ft_strlen(map[0]);

    x = 0;
    while (x < width)
    {
        if (map[0][x] != '1' || map[height - 1][x] != '1')
            return 0;
        x++;
    }

    y = 0;
    while (y < height)
    {
        if (!map[y] || (int)ft_strlen(map[y]) != width)  
            return 0;
        if (map[y][0] != '1' || map[y][width - 1] != '1')
            return 0;
        y++;
    }
    return 1;
}

int verification_map(char **map)
{
    int collection = 0;
    int exit = 0;
    int player = 0;

    if (!map || !map[0])
        return 0;

    if (!verification_caractere(map, &collection, &exit, &player))
        return 0;
    
    if (player != 1 || exit != 1 || collection < 1)
        return 0;
    
    if (!verification_line(map) || !check_borders(map))
        return 0;

    return 1;
}
