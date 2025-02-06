#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

# define ESC_KEY 65307
#define TILE_SIZE 64
typedef struct s_vars 
{
    void *mlx;
    void *win;
    void *img;
    char **map;
    void *img_player;
    void *img_l3zwa;
    void *img_hait;
    void *img_ard;
    void *img_coin;
    void *img_win;
    int width;
    int height;
    int player_x;
    int player_y;
    int fd;
    int move_nb;
    int word_coin;
}   t_vars;


// get_next_line
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

// split
int     count(char const *s, char c);
char	*copy(char *str, int start, int end);
char	**ft_split(char const *s, char c);

// so_long
char	**get_maps(int fd);

// verification map
int		verification_caractere(t_vars *game, int *collection, int *exit, int *player);
int		verification_line(t_vars *game);
int		verification_map(t_vars *game);
int		check_borders(t_vars *game);

// so_long-util
int		close_window(t_vars *game);
void	ft_exit(t_vars *game);
void	ft_free_map(t_vars *game);

//img map
void render_map( t_vars *game);

//move 
void find_player(t_vars *game);
int handle_key(int keycode, void *param);
void    cont_coin(t_vars *game);


#endif