











#include "../../includes/lem_in.h"

void	which_command(t_lemin *l, int i)
{
	l->commands++;
	if (ft_strcmp(l->f[i], "##start") == 0)
		l->flag_start = 1;
	else if (ft_strcmp(l->f[i], "##end") == 0)
		l->flag_end = 1;
}

int		map_room_and_stock(t_lemin *l)
{
	int	i;

	i = l->start;
	while (l->f[i] != NULL)
	{
		if (l->f[i][0] && l->f[i][0] == '#' && l->f[i][1] && l->f[i][1] == '#')
			which_command(l, i);
		else if (l->f[i][0] && l->f[i][0] == '#' &&
				(!l->f[i][1] || (l->f[i][1] && l->f[i][1] != '#')))
			l->comments++;
		else if (ft_nb_occur_char_in_str(l->f[i], " ") == 2 &&
				l->f[i][0] && l->f[i][0] != '#')
			check_if_room(l->f[i], l);
		else if (l->f[i][0] && l->f[i][0] != '#' && ft_strstr(l->f[i], "-"))
		{
			l->start = i;
			return (1);
		}
		else
			return (2);
		i++;
	}
	l->start = i;
	return (0);
}
