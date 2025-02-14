#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

# define ESC_KEY 65307
# define TILE_SIZE 64

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	**map;
	void	*img_player;
	void	*img_l3zwa;
	void	*img_hait;
	void	*img_ard;
	void	*img_coin;
	void	*img_win;
	void	*img_home;
	void	*animation[7];
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		fd;
	int		move_nb;
	int		word_coin;
	int		cont_coin; ///
	int		current_frame;
	int		frame_delay;
	int		frame_counter;
	int		enemy_x;
	int		enemy_y;
	int		dir;
	int		enemy_speed;
	char 	*copy_map;
}			t_vars;

// get_next_line
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*get_next_line(int fd);

// split
int			count(char const *s, char c);
char		*copy(char *str, int start, int end);
char		**ft_split(char const *s, char c);

// so_long
char		**get_maps(int fd);
int			load_images(t_vars *game, int *width, int *height);
int			open_map(char *filename);
int			create_window(t_vars *game);
int			init_game(t_vars *game, int fd);
// verification map
int			verification_caractere(t_vars *game, int *collection, int *exit,
				int *player);
int			verification_line(t_vars *game);
int			verification_map(t_vars *game);
int			check_borders(t_vars *game);

// so_long-util
int			close_window(t_vars *game);
void		ft_exit(t_vars *game);
void		ft_free_map(t_vars *game);
char		*ft_itoa(int n);

// img map
void		render_map(t_vars *game);
void		animation_image(t_vars *game);
int			animation_loop(t_vars *game);
void		free_animation(t_vars *game);
int			game_loop(t_vars *game);
// move
void		find_player(t_vars *game);
int			handle_key(int keycode, void *param);
void		cont_coin(t_vars *game);
void		player_coin(t_vars *game);
void		move_player(t_vars *game, int y_move, int x_move);

// enyme
int			game_loop(t_vars *game);
void		check_enemy_collision(t_vars *game);
void		find_enemy(t_vars *game);
void		move_enemy(t_vars *game);

void free_mlx(t_vars *game);
#endif