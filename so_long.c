#include "so_long.h"

char **get_maps(int fd)
{
    char *line;
    char *all_lines ;
    char **map_array;
    char *temp;
    
    all_lines = NULL;
    while ((line = get_next_line(fd)) != NULL)
    {
        if (all_lines == NULL)
            all_lines = ft_strdup(line);
        else
        {
            temp = ft_strjoin(all_lines, line);
            free(all_lines);
            all_lines = temp;
        }
        free(line);
    }

    if (!all_lines) 
        return NULL;

    map_array = ft_split(all_lines, '\n');
    free(all_lines);
    
    return map_array;
}

int main(int ac, char **av)
{  
    t_vars game = {0};
    int width; 
    int height;
    
    if (ac != 2)
    {
        printf("Error: khssek tdir argument wahd\n");
        return 1;
    }
    
    game.fd = open(av[1], O_RDONLY);
    if (game.fd < 0)
    {
        printf("Error: l fichier ma kaynch ola ma kayt7lch\n");
        return 1;
    }
    
    game.map = get_maps(game.fd);
    close(game.fd);
    
    if (!game.map)
    {
        printf("Error: ma qdertch nloadi l map\n");
        return 1;
    }
    
    if (!verification_map(&game))
    {
        printf("Error: l map 3ndha mochkila\n");
        ft_free_map(&game);
        return 1;
    }
    
    game.mlx = mlx_init();
    if (!game.mlx)
    {
        printf("Error: mlx ma bghatch tinitilizi\n");
        ft_free_map(&game);
        return 1;
    }
    
    game.win = mlx_new_window(game.mlx, game.width * 50, game.height * 50, "So Long");
    if (!game.win)
    {
        printf("Error: ma qdertch n7ll l window\n");
        ft_exit(&game);
    }

    game.img_player = mlx_xpm_file_to_image(game.mlx, "assets/player.xpm", &width, &height);
    game.img_l3zwa = mlx_xpm_file_to_image(game.mlx, "assets/l3azwa.xpm", &width, &height);
    game.img_hait = mlx_xpm_file_to_image(game.mlx, "assets/haiiiit.xpm", &width, &height);
    game.img_ard = mlx_xpm_file_to_image(game.mlx, "assets/lard.xpm", &width, &height);
    
    if (!game.img_player || !game.img_l3zwa || !game.img_hait || !game.img_ard)
    {
        printf("Error: ma qdertch nloadi l images\n");
        ft_exit(&game);
    }
    
    render_map(&game);
    mlx_key_hook(game.win, handle_key, &game);
    mlx_hook(game.win, 17, 0, close_window, &game);
    
    mlx_loop(game.mlx);
    
    return 0;
}