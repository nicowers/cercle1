CC = cc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror 
SRC = ft_printf.c ft_printf_utils.c ft_utils_hexa.c
OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re : fclean all