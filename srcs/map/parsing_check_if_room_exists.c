











#include "../../includes/lem_in.h"

static void	get_room_id(t_lemin *l, char **array)
{
	l->room = l->begin;
	l->froom1 = -1;
	l->froom2 = -1;
	while (l->room)
	{
		if (ft_strcmp(l->room->name, array[0]) == 0)
		{
			l->froom1 = l->room->id;
		}
		if (ft_strcmp(l->room->name, array[1]) == 0)
		{
			l->froom2 = l->room->id;
		}
		l->room = l->room->next;
	}
}

void		check_if_rooms_exists(t_lemin *l, char **array)
{
	get_room_id(l, array);
	l->room = l->begin;
	if (l->froom1 == -1 || l->froom2 == -1)
	{
		ft_free_double_array((void**)array);
		free_pipes(l,
			"\033[091mError: pipes linked to unknown rooms\033[0m");
	}
		l->pipes[l->froom2][l->froom1] = 1;
		l->pipes[l->froom1][l->froom2] = 1;
}
