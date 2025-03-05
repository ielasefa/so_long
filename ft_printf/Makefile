
NAME = libftprintf.a 
SRC =     ft_printf.c   printf_add.c    printf_char.c \
		printf_hex.c    printf_nbr.c    printf_string.c  printf_unsg.c
CC = cc 
CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
all : $(NAME)

$(NAME) : $(OBJ) 
	ar rcs $(NAME) $(OBJ)	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean : 
	rm -f $(OBJ)
	
fclean : clean 
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
