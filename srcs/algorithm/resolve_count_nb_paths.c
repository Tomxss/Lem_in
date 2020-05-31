











#include "../../includes/lem_in.h"

void		count_nb_paths(t_lemin *l)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	l->lookup = (int *)malloc(sizeof(int) * (unsigned long)(l->nb_rooms));
	if (!l->lookup)
		free_pipes_and_sum(l, "\033[091mAllocation error\033[0m");
	while (i < l->nb_rooms)
		l->lookup[i++] = -1;
	i = 0;
	l->sorted = (int *)malloc(sizeof(int) * (unsigned long)(l->nb_rooms));
	if (!l->sorted)
		free_pipes_and_sum(l, "\033[091mAllocation error033[0m");
	while (i < l->nb_rooms)
		l->sorted[i++] = -1;
	resolve_nb_paths(l, l->room_start, &j);
	if (l->nb_path == 0)
		free_pipes_and_sum(l, "\033[091mNo possible path\033[0m");
	free(l->lookup);
}
