#include "../../includes/lem_in.h"

static void	make_array_duplicate(t_lemin *l)
{
	l->dup = (char **)malloc(sizeof(char*) * (unsigned long)(l->nb_rooms + 1));
	if (l->dup == NULL)
		free_check_if_room(l,
				"\033[091mError during memory allocation\033[0m");
	l->room = l->begin;
	while (l->room != NULL)
	{
		l->dup[l->room->id] = ft_strdup(l->room->name);
		l->room = l->room->next;
	}
	l->room = l->begin;
	l->dup[l->nb_rooms] = NULL;
}

void		read_map(t_lemin *l)
{
	handle_file(l);
	map_ants_number(l);
	if (map_room_and_stock(l) == 2)
		free_check_if_room(l,
				"\033[091mError: The map is badly formatted\033[0m");
	make_array_duplicate(l);
	map_pipes_and_stock(l);
	check_end_and_start(l);
}
