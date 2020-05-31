CC		= gcc

NAME	=	libft.a

FLAGS = -Wall -Werror -Wextra

INCLUDES	=	-I ./includes

OBJDIR	=	objs

SRC =	$(wildcard ft_*.c)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< $(INCLUDES)

clean:
	@rm -rf $(OBJ)

fclean:	clean
	@rm -rf $(NAME)

re: fclean all	

.PHONY: all clean fclean re
