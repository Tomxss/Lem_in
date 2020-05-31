CC			=	gcc
NAME		=	lem-in
FLAGS		=	-Wall -Wextra -Werror -g
LIBDIR		=	libft
LIB 		=	$(LIBDIR)/libft.a

INCLUDES	= 	-I ./includes
INCLUDE		=	./includes

OBJDIR		= 	objs

OBJDIR_ALGO	=	objs/
OBJDIR_MAP	=	objs/

SRCDIR_ALGO	=	srcs/algorithm
SRCDIR_MAP	=	srcs/map

SRC_ALGO 	=	main.c debug_mode.c\
				resolve_isolated_roms.c resolve_count_nb_paths.c\
				print.c resolve_remove_useless_paths.c free2.c\
				resolve_check_if_solution_exists.c resolve_bfs.c resolve.c\
				resolve_delete_other_paths.c resolve_nb_paths.c\
				resolve_calculate_different_paths.c print_tab_pipes.c\
				resolve_get_ants.c resolve_create_ant_result.c

SRC_MAP		=	parsing.c parsing_ants_number.c parsing_start_end_exists.c\
				parsing_check_if_room.c parsing_room_and_stock.c\
				parsing_pipes_and_stock.c parsing_check_room_name.c\
				parsing_check_end_and_start.c get_file.c free.c useful.c\
				init.c parsing_check_if_room_exists.c

OBJS_ALGO	=	$(addprefix $(OBJDIR_ALGO)/, $(SRC_ALGO:.c=.o))\
				$(addprefix $(OBJDIR_MAP)/, $(SRC_MAP:.c=.o))

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJDIR_ALGO) $(LIB) $(OBJS_ALGO) $(INCLUDE)
	@$(CC) $(FLAGS) -o $@ $(OBJS_ALGO) $(LIB)

$(LIB):
	@make -C $(LIBDIR)

$(OBJDIR_ALGO)/%.o: $(SRCDIR_ALGO)/%.c
	@$(CC) $(FLAGS) -c $^ -o $@ $(INCLUDES)

$(OBJDIR_MAP)/%.o: $(SRCDIR_MAP)/%.c
	@$(CC) $(FLAGS) -c $^ -o $@ $(INCLUDES)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBDIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all

.PHONY: clean all re fclean directory
