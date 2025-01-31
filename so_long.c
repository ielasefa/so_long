#include "so_long.h"

char **get_maps(int fd)
{
    char *line;
    char *all_lines = NULL;
    char **map_array;
    
    while ((line = get_next_line(fd)) != NULL)
    {
        if (all_lines == NULL)
            all_lines = ft_strdup(line);
        else
        {
            char *temp = ft_strjoin(all_lines, line);
            free(all_lines);
            all_lines = temp;
        }
        free(line);
    }
    
    if (!all_lines) // Vérifier si all_lines est NULL avant ft_split
        return NULL;

    map_array = ft_split(all_lines, '\n');
    free(all_lines);
    
    return map_array;
}

int main(int ac, char **av)
{
    void *mlx;
    void *win;
    char **map;
    int fd;
    
    if (ac != 2)
    {
        printf("Error: wrong number of arguments\n");
        return 1;
    }

    fd = open(av[1], O_RDONLY);
    if (fd < 0)
    {
        printf("Error: cannot open file\n");
        return 1;
    }

    map = get_maps(fd);
    close(fd);
    
    if (!map)
    {
        printf("Error: map loading failed\n");
        return 1;
    }

    if (!verification_map(map)) 
    {
        printf("------------Error in map----------\n");
        return 1;
    }

    mlx = mlx_init();
    if (!mlx)
    {
        printf("Error: mlx initialization failed\n");
        return 1;
    }

    win = mlx_new_window(mlx, 800, 600, "so long");
    mlx_pixel_put(mlx, win, 400, 300, 0xffff00);

    mlx_loop(mlx);

    int i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);

    return 0;
}
