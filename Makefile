NAME = so_long

SRCS = get_next_line.c get_next_line_utils.c so_long.c so_long_utils.c \
       split.c verification_map.c move.c image_map.c \

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

.PHONY: all clean fclean re