NAME = so_long

SRCS = enemy.c       get_next_line.c        move.c           split.c \
	flood_fill.c  get_next_line_utils.c  so_long.c        verification_map.c \
      image_map.c            so_long_utils.c free.c

OBJS = $(SRCS:.c=.o)

CC = gcc 
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = /usr/local/include
MLX_LIB = -L/usr/local/lib -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_LIB)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY: $(OBJ) $(BOBJ)
.PHONY: all clean fclean re