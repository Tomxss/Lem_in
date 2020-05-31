











#include "../../includes/lem_in.h"

static void	get_shots_min(t_lemin *l, t_path **next)
{
	int	nbr_shots_min;

	nbr_shots_min = 0;
	l->path->different_path += 1;
	nbr_shots_min = l->path->nbr_shots + (*next)->nbr_shots;
	if (l->path->nbr_shots_min == 0 || l->path->nbr_shots_min < nbr_shots_min)
		l->path->nbr_shots_min = nbr_shots_min;
}

static void	find_different_paths(t_lemin *l, t_path **next)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	*next = (*next)->next;
	i = 0;
	while (l->path->path[i] != l->room_end && flag == 0)
	{
		j = 0;
		while ((*next)->path[j] != l->room_end && flag == 0)
		{
			if (l->path->path[i] == (*next)->path[j])
				flag = 1;
			j++;
		}
		i++;
	}
	if (flag == 0)
		get_shots_min(l, next);
	flag = 0;
}

void		calculate_different_paths(t_lemin *l)
{
	t_path	*next;

	next = NULL;
	l->path = l->path_begin;
	next = l->path;
	while (l->path)
	{
		while (next->next)
			find_different_paths(l, &next);
		l->path = l->path->next;
		next = l->path;
	}
}
