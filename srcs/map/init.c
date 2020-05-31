#include "../../includes/lem_in.h"

static void	init_ants2(t_lemin *l)
{
	l->nb_ants = 0;
	l->nb_pipes = 0;
	l->nb_rooms = 0;
	l->flag_start = -1;
	l->flag_end = -1;
	l->id = 0;
	l->comments = 0;
	l->commands = 0;
	l->start = 0;
	l->nb_path = 0;
	l->room_start = -1;
	l->room_end = -1;
	l->debug = 0;
	l->flag_start_to_end = 0;
	l->froom1 = -1;
	l->froom2 = -1;
	l->nb_path_final = 0;
	l->ant_finish = 0;
}

void		init_ants(t_lemin *l)
{
	l->path = NULL;
	l->path_begin = NULL;
	l->best_path = NULL;
	l->solution = NULL;
	l->solution_begin = NULL;
	l->room = NULL;
	l->begin = NULL;
	l->sum = NULL;
	l->lookup = NULL;
	l->level = NULL;
	l->sorted = NULL;
	l->dup = NULL;
	l->f = NULL;
	l->string_file = NULL;
	l->pipes = NULL;
	l->visited = NULL;
	init_ants2(l);
}

void		handle_flags(int argc, char **argv, t_lemin *l)
{
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "help") == 0)
		{
			ft_putendl("\033[094mAvailable Flags: \n");
			ft_putendl("-d : debug mode");
			ft_putstr("\033[0m");
			exit(1);
		}
		else if (argv[1][0] == '-')
		{
			if (ft_strchr(argv[1], 'd') != NULL)
				l->debug = 1;
			else
				print_error(ft_putendl_fd, "Error: no such flag available", STDERR_FILENO, l);
		}
	}
}
