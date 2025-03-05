NAME = so_long
SRCS = enemy.c       get_next_line.c        move.c           split.c \
	flood_fill.c  get_next_line_utils.c  so_long.c        verification_map.c \
      image_map.c            so_long_utils.c free.c 	ft_itoi.c 
OBJS = $(SRCS:.c=.o)
CC = gcc 
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = /usr/local/include
MLX_LIB = -L/usr/local/lib -lmlx -lXext -lX11

PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

$(NAME): $(PRINTF_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_LIB) $(PRINTF_LIB)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(PRINTF_DIR) -c $< -o $@

clean:
	make -C $(PRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.SECONDARY: $(OBJS)
.PHONY: all clean fclean re