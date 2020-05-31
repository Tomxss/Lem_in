
#include "../../includes/lem_in.h"

static void	push_ant_front(t_lemin *l, t_room *path, int *ant_nb)
{
	path->ant = *ant_nb;
	ft_putstr("L");
	ft_putstr(ft_itoa(path->ant));
	ft_putstr("-");
	ft_putstr(l->dup[path->id]);
	ft_putchar(' ');
	(*ant_nb)++;
	if (path->id == l->room_end)
		l->ant_finish++;
}

static void	ants_vacuum(t_lemin *l, t_room *path, int *ant_nb)
{
	if (path->next->id == l->room_start && *ant_nb <= l->nb_ants)
		push_ant_front(l, path, ant_nb);
	else if (path->next->ant > 0 && path->id != l->room_end &&
			path->next->id != l->room_start)
	{
		path->ant = path->next->ant;
		path->next->ant = -1;
			ft_putstr("L");
			ft_putstr(ft_itoa(path->ant));
			ft_putstr("-");
			ft_putstr(l->dup[path->id]);
			ft_putchar(' ');
	}
	else if (path->next->ant > 0 && path->id == l->room_end &&
			l->ant_finish < l->nb_ants)
	{
		path->ant = path->next->ant;
		path->next->ant = -1;
			ft_putstr("L");
			ft_putstr(ft_itoa(path->ant));
			ft_putstr("-");
			ft_putstr(l->dup[path->id]);
			ft_putchar(' ');
		l->ant_finish++;
	}
}

void		get_ants(t_lemin *l)
{
	int		ant_nb;
	int		i;
	t_room	*path;

	ant_nb = 1;
	path = NULL;
	l->ant_finish = 0;
	while (l->ant_finish < l->nb_ants)
	{
		i = 0;
		while (l->result[i])
		{
			path = l->result[i];
			while (path->next)
			{
				ants_vacuum(l, path, &ant_nb);
				path = path->next;
			}
			i++;
		}
		ft_putchar('\n');
	}
}
