











#include "../../includes/lem_in.h"

static void	check_sum_end_start(t_lemin *l)
{
	if (l->sum[l->room_start] == 0)
	{
		free(l->sum);
		free_pipes(l, "\033[091mError: Starting room not connected\033[0m");
	}
	if (l->sum[l->room_end] == 0)
	{
		free(l->sum);
		free_pipes(l, "\033[091mError: End room not connected\033[0m");
	}
}

void		remove_useless_paths(t_lemin *l)
{
	create_sum_array(l);
	update_sum_array(l);
	check_sum_end_start(l);
	check_if_solution_exists(l);
	cross_check(l, l->room_start);
	cross_check(l, l->room_end);
	update_sum_array(l);
	check_for_isolated_rooms(l);
	count_nb_paths(l);
}
