 #ifndef SO_LONG_H
 #define SO_LONG_H

#include <mlx.h> 
#include <stdio.h>
#include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

//get_next_line
size_t	        ft_strlen(const char *s);
char	        *ft_strdup(const char *s1);
char	        *ft_strchr(const char *s, int c);
char	        *ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

//split
int         count(char const *s, char c);
char	    *copy(char *str, int start, int end);
char	    **ft_split(char const *s, char c);

//so_long
char **get_maps(int fd);

//verification map
int verification_caractere(char **map, int *collection, int *exit, int *player);
int verification_line(char **map);
int verification_map(char **map);
int check_borders(char **map);

#endif