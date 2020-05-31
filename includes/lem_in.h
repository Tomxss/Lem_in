
#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include <stdbool.h>

typedef struct		s_room
{
	struct s_room	*next;
	int				id;
	int				ant;
	int				length;
	char			*name;
}					t_room;

typedef struct		s_path
{
	struct s_path	*next;
	int				*path;
	int				nbr_shots;
	int				different_path;
	int				nbr_shots_min;
	int				nbr;
	int				padding[2];
}					t_path;

typedef struct		s_queue
{
	int				id;
	int				padding[3];
	struct s_queue	*next;
}					t_queue;

typedef struct		s_lemin
{
	struct s_path	*path;
	struct s_path	*path_begin;
	struct s_path	*best_path;
	struct s_path	*solution;
	struct s_path	*solution_begin;
	struct s_room	*room;
	struct s_room	*begin;
	struct s_room	**result;
	int				*sum;
	int				*lookup;
	int				*level;
	int				*sorted;
	char			**dup;
	char			**f;
	char			*string_file;
	bool			**pipes;
	bool			*visited;
	int				nb_ants;
	int				nb_pipes;
	int				nb_rooms;
	int				flag_start;
	int				flag_end;
	int				id;
	int				comments;
	int				commands;
	int				start;
	int				nb_path;
	int				nb_path_final;
	int				ant_finish;
	int				room_start;
	int				room_end;
	int				padding;
	int				froom1;
	int				froom2;
	char			debug;
	char			padding1[6];
	bool			flag_start_to_end;
	bool			padding2[1];
}					t_lemin;

void				init_ants(t_lemin *l);
void				handle_flags(int argc, char **argv, t_lemin *l);
void				handle_file(t_lemin *l);
void				print_error(void (*function)(const char *, int fd),
					const char *str, int fd, t_lemin *l);

void				free_l_file(char **str);
void				free_map_start(t_lemin *l, char *str);
void				free_map_end(t_lemin *l, char *str);
void				free_check_if_room(t_lemin *l, char *str);
void				free_lst_name(t_lemin *l);
void				ft_free_array_bool(bool **array);
void				free_queue(t_queue *lst);
void				free_pipes(t_lemin *l, char *str);
void				free_pipes_and_sum(t_lemin *l, char *str);
void				free_at_end(t_lemin *l);
void				free_result(t_lemin *l);

void				read_map(t_lemin *l);
void				map_ants_number(t_lemin *l);
void				map_start_end_exists(t_lemin *l);
void				map_rooms_error_cases(t_lemin *l);
void				map_room_name(t_lemin *l);
int					check_if_room(char *str, t_lemin *l);
int					map_room_and_stock(t_lemin *l);
void				check_end_and_start(t_lemin *l);
int					map_pipes_and_stock(t_lemin *l);
void				check_is_print(char *str, t_lemin *l);
void				check_begin_with_l(char *str, t_lemin *l);
void				check_for_hyphen(char **array, t_lemin *l);
void				check_if_name_already_exists(char **array, t_lemin *l);
void				which_command(t_lemin *l, int i);
void				check_coordonates(char **array, t_lemin *l);
void				map_init_array_pipes(t_lemin *l);
void				stock_pipes(char *str, t_lemin *l);
void				check_if_rooms_exists(t_lemin *l, char **array);

void				check_for_isolated_rooms(t_lemin *l);
void				update_sum_array(t_lemin *l);
void				create_sum_array(t_lemin *l);
void				count_nb_paths(t_lemin *l);
void				cross_check(t_lemin *l, int room_start);
void				check_if_solution_exists(t_lemin *l);
void				resolve(t_lemin *l);
void				remove_useless_paths(t_lemin *l);
void				delete_other_paths(t_lemin *l);
void				calculate_different_paths(t_lemin *l);
void				already_explored(t_lemin *l, int *j, int room, int i);
void				back_in_stack(t_lemin *l, int *j, int room, int i);
int					resolve_nb_paths(t_lemin *l, int room, int *j);
void				get_ants(t_lemin *l);
void				create_ant_result(t_lemin *l);

void				print_equivalence_array(t_lemin *l);
void				ft_print_array_pipes(t_lemin *l);
void				print_resume(t_lemin *l);
void				print_possible_paths(t_lemin *l);
void				print_result(t_lemin *l);
void				print_debug(t_lemin *l);

#endif
