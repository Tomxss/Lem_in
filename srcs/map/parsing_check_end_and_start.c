











#include "../../includes/lem_in.h"

static void	case_start_end_identical(t_lemin *l)
{
	if (l->room_start == l->room_end)
	{
		ft_free_double_array((void**)l->dup);
		ft_free_double_array((void**)l->pipes);
		ft_free_double_array((void**)l->f);
		free(l->string_file);
		free_lst_name(l);
		print_error(ft_putendl_fd,
			"\033[091mError: The start and end rooms are identical\033[0m",
			STDERR_FILENO, l);
	}
}

static void	case_no_rooms(t_lemin *l)
{
	if (l->nb_rooms == 0)
	{
		ft_free_double_array((void**)l->dup);
		ft_free_double_array((void**)l->pipes);
		ft_free_double_array((void**)l->f);
		free(l->string_file);
		free_lst_name(l);
		print_error(ft_putendl_fd,
				"\033[091mError: No room is present\033[0m",
				STDERR_FILENO, l);
	}
}

static void	case_no_pipes(t_lemin *l)
{
	if (l->nb_pipes == 0)
	{
		ft_free_double_array((void**)l->dup);
		ft_free_double_array((void**)l->pipes);
		ft_free_double_array((void**)l->f);
		free(l->string_file);
		free_lst_name(l);
		print_error(ft_putendl_fd,
				"\033[091mError: No pipe is present\033[0m",
				STDERR_FILENO, l);
	}
}

static void	case_no_end_start(t_lemin *l)
{
	if (l->room_start == -1)
	{
		ft_free_double_array((void**)l->dup);
		ft_free_double_array((void**)l->pipes);
		ft_free_double_array((void**)l->f);
		free(l->string_file);
		free_lst_name(l);
		print_error(ft_putendl_fd,
				"\033[091mError: No starting room\033[0m",
				STDERR_FILENO, l);
	}
	if (l->room_end == -1)
	{
		ft_free_double_array((void**)l->dup);
		ft_free_double_array((void**)l->pipes);
		ft_free_double_array((void**)l->f);
		free(l->string_file);
		free_lst_name(l);
		print_error(ft_putendl_fd,
				"\033[091mError: No end room\033[0m",
				STDERR_FILENO, l);
	}
}

void		check_end_and_start(t_lemin *l)
{
	case_no_rooms(l);
	case_no_pipes(l);
	case_no_end_start(l);
	case_start_end_identical(l);
}
