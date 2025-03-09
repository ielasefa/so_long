/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:34:02 by iel-asef          #+#    #+#             */
/*   Updated: 2025/03/05 17:34:04 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stddef.h>
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
	void	*img_wall;
	void	*img_floor;
	void	*img_coin;
	void	*img_win;
	void	*img_home;
	void	*animation[5];
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		fd;
	int		move_nb;
	int		word_coin;
	int		cont_coin;
	int		current_frame;
	int		frame_delay;
	int		frame_counter;
	int		enemy_x;
	int		enemy_y;
	int		home_x;
	int		home_y;
	int		dir;
	int		enemy_speed;
	char	**copy_map;
	int		player_x_f;
	int		player_y_f;
}			t_vars;

typedef struct s_verification
{
	int		collect;
	int		exit;
	int		player;
	int		collect_f;
	int		exit_f;
	int		player_f;
	int		total_coin_f;

}			t_verification;

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

// main.c
int			load_images(t_vars *game, int *width, int *height);
int			create_window(t_vars *game);

int			init_game(t_vars *game, t_verification *ver, int fd);
/// open_map
int			open_map(char *filename);
void		free_resources(char *all_lines, char *line);
char		**get_maps(int fd);
char		*add_line(char *all_lines, char *line);

// verification map
int			verification_caractere(t_vars *game, int *collection, int *exit,
				int *player);
int			verification_line(t_vars *game);
int			verification_map(t_vars *game, t_verification *ver);
int			check_borders(t_vars *game);
void		handle_player(t_vars *game, t_verification *ver, int x, int y);

int			verification_map_2(t_vars *game, t_verification *ver);

// so_long-util
int			close_window(t_vars *game);
void		ft_exit(t_vars *game);
void		ft_free_map(t_vars *game);
char		*ft_itoa(int n);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

// img map
void		render_map(t_vars *game);
void		animation_image(t_vars *game);
int			animation_loop(t_vars *game);
void		free_animation(t_vars *game);
int			game_loop(t_vars *game);
void		render_tile(t_vars *game, int x, int y);
void		render_player(t_vars *game);

// move
void		find_player(t_vars *game);

int			handle_key(int keycode, void *param);
void		cont_coin(t_vars *game);
void		player_coin(t_vars *game);
void		move_player(t_vars *game, int y_move, int x_move);

// flloot fill
void		flood_fill(t_vars *game, int x, int y, t_verification *ver);

int			validate_flood_fill(t_vars *game, t_verification *ver);

void		copy_map(t_vars *game);
void		find_player_f(t_vars *game);

// ift_itio
char		*ft_itoa(int n);
int			len_itoi(int n);
void		*free_static(void *ptr);

// animation
int			animation_loop(t_vars *game);
void		render_collectibles_animation(t_vars *game);
#endif
