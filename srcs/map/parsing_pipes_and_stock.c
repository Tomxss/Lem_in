











#include "../../includes/lem_in.h"

static bool	**ft_create_array_bool(unsigned long x, unsigned long y)
{
	bool	**array;
	int		i;
	int		j;

	array = NULL;
	i = 0;
	j = 0;
	array = (bool **)malloc(sizeof(bool *) * (y + 1));
	if (array == NULL)
		return (NULL);
	while ((unsigned long)i < y)
	{
		array[i] = (bool *)malloc(sizeof(bool) * x);
		if (array[i] == NULL)
		{
			ft_free_double_array((void**)array);
			return (NULL);
		}
		while ((unsigned long)j < x)
			array[i][j++] = '\0';
		j = 0;
		i++;
	}
	array[i] = NULL;
	return (array);
}

void		map_init_array_pipes(t_lemin *l)
{
	l->pipes = ft_create_array_bool((unsigned long)l->nb_rooms,
			(unsigned long)l->nb_rooms);
	if (l->pipes == NULL)
	{
		ft_free_double_array((void**)l->dup);
		free_check_if_room(l,
				"\033[091mError during memory allocation\033[0m");
	}
	l->room = l->begin;
	l->pipes[l->nb_rooms] = NULL;
}

void		stock_pipes(char *str, t_lemin *l)
{
	char	**array;

	array = NULL;
	array = ft_strsplit(str, '-');
	if (array == NULL || array[0] == NULL || array[1] == NULL)
	{
		free_pipes(l,
				"\033[091mError: Poorly formatted pipes\033[0m");
	}
	if (ft_strcmp(array[0], array[1]) == 0)
	{
		ft_free_double_array((void**)array);
		free_pipes(l, "\033[091mError: A room is connected to itself\
				\033[0m");
	}
	if (ft_nb_occur_char_in_str(str, "-") > 1)
	{
		ft_free_double_array((void**)array);
		free_pipes(l,
				"\033[091mError: One or more pipes are badly formatted\
				\033[0m");
	}
	check_if_rooms_exists(l, array);
	ft_free_double_array((void**)array);
	l->nb_pipes++;
}

int			map_pipes_and_stock(t_lemin *l)
{
	int	i;

	i = l->start;
	map_init_array_pipes(l);
	while (l->f[i] != NULL)
	{
		if (ft_strcmp(l->f[i], "##start") == 0)
			free_pipes(l, "\033[091mError: Invalid starting room\033[0m");
		else if (ft_strcmp(l->f[i], "##end") == 0)
			free_pipes(l, "\033[091mError: Invalid end room\033[0m");
		else if (l->f[i][0] && l->f[i][0] == '#' &&
				(!l->f[i][1] || (l->f[i][1] && l->f[i][1] != '#')))
			i++;
		else if (l->f[i][0] && l->f[i][0] == '#' &&
				l->f[i][1] && l->f[i][1] == '#')
			i++;
		else if (ft_nb_occur_char_in_str(l->f[i], " ") == 2 &&
				l->f[i][0] && l->f[i][0] != '#')
			free_pipes(l, "\033[091mError: Badly formatted map\033[0m");
		else if (l->f[i][0] && l->f[i][0] != '#' && ft_strstr(l->f[i], "-"))
			stock_pipes(l->f[i++], l);
		else
			return (1);
	}
	return (0);
}
