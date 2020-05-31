#include "../../includes/lem_in.h"

void		print_resume(t_lemin *l)
{
	ft_putendl("\033[94m---------- Summary ----------\n\033[0m");
	ft_putstr("\033[095mNumber of Ants : \033[0m");
	ft_putnbr(l->nb_ants);
	ft_putstr("\n\033[095mNumber of Rooms : \033[0m");
	ft_putnbr(l->nb_rooms);
	ft_putstr("\n\033[095mNumber of pipes: \033[0m");
	ft_putnbr(l->nb_pipes);
	ft_putstr("\n\033[095mStarting Room : \033[0m");
	ft_putstr(l->dup[l->room_start]);
	ft_putstr("\n\033[095mEnd Room : \033[0m");
	ft_putstr(l->dup[l->room_end]);
	ft_putendl("\n");
}

void		print_equivalence_array(t_lemin *l)
{
	int	i;

	i = 0;
	ft_putstr("\033[94m---------- Relations id | ");
	ft_putendl("Room Name ----------\n\033[0m");
	while (i < l->nb_rooms)
	{
		ft_putnbr(i);
		ft_putchar(' ');
		if (i < 10)
			ft_putchar(' ');
		ft_putstr("| ");
		ft_putstr(l->dup[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}

void		print_result(t_lemin *l)
{
	int j;

	j = 0;
	ft_putendl("\033[94m---------- Selected Paths ----------\n\033[0m");
	l->path = l->solution_begin;
	while (l->path)
	{
		j = 0;
		ft_putstr(l->dup[l->room_start]);
		ft_putstr("\033[090m -> \033[0m");
		while (l->path->path[j] != l->room_end)
		{
			ft_putstr(l->dup[l->path->path[j++]]);
			ft_putstr("\033[090m -> \033[0m");
		}
		ft_putstr(l->dup[l->room_end]);
		ft_putchar('\n');
		l->path = l->path->next;
	}
	ft_putchar('\n');
}

void		print_possible_paths(t_lemin *l)
{
	int j;

	j = 0;
	ft_putendl("\033[94m---------- Possible Solutions ----------\n\033[0m");
	ft_putstr("\033[095mNumber of possible Solutions: \033[0m");
	ft_putnbr(l->nb_path);
	ft_putendl("\n");
	l->path = l->path_begin;
	while (l->path)
	{
		j = 0;
		ft_putstr(l->dup[l->room_start]);
		ft_putstr("\033[090m -> \033[0m");
		while (l->path->path[j] != l->room_end)
		{
			ft_putstr(l->dup[l->path->path[j++]]);
			ft_putstr("\033[090m -> \033[0m");
		}
		ft_putstr(l->dup[l->room_end]);
		ft_putchar('\n');
		l->path = l->path->next;
	}
	ft_putchar('\n');
}
