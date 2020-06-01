










#include <stdio.h>
#include "../../includes/lem_in.h"

void		check_coordonates(char **array, t_lemin *l)
{
	int	ret;
	long MIN = -2147483648;

	ret = -1;
	if (array[1][0] && array[1][0] == '-' && array[1][1])
		ret = ft_check_if_num(&array[1][1]);
	else
		ret = ft_check_if_num(array[1]);
	if (ret != 0)
	{
		ft_free_double_array((void**)array);
		free_check_if_room(l,
			"\033[091mError: One or more X coordinates are incorrect\
			\033[0m");
	}

	if (ft_atoi_max_min(&array[1][0]) > 2147483647 || ft_atoi_max_min(&array[1][0]) < MIN)	// -7 < -216377238
	{
		ft_free_double_array((void**)array);
		free_check_if_room(l,
			"\033[091mError: One or more X coordinates are incorrect\
			\033[0m");
	}

	if (array[2][0] && array[2][0] == '-' && array[2][1])
		ret = ft_check_if_num(&array[2][1]);
	else
		ret = ft_check_if_num(array[2]);
	if (ret != 0)
	{
		ft_free_double_array((void**)array);
		free_check_if_room(l,
			"\033[091mError: One or more Y coordinates are incorrect\
			\033[0m");
	}

	if (ft_atoi_max_min(&array[2][0]) > 2147483647 || ft_atoi_max_min(&array[2][0]) < MIN)	// -7 < -216377238
	{
		ft_free_double_array((void**)array);
		free_check_if_room(l,
			"\033[091mError: One or more Y coordinates are incorrect\
			\033[0m");
	}
}

static void	check_command_rooms(t_lemin *l)
{
	if (l->flag_start == 1)
	{
		l->room_start = l->room->id;
		l->flag_start = 0;
	}
	if (l->flag_end == 1)
	{
		l->room_end = l->room->id;
		l->flag_end = 0;
	}
}

static void	stock_room_name(t_lemin *l, char **array)
{
	if (!l->begin)
	{
		l->room = (t_room*)malloc(sizeof(t_room));
		if (!l->room)
			free_check_if_room(l, "\033[091mMalloc error\033[0m");
		l->begin = l->room;
	}
	else
	{
		l->room->next = (t_room*)malloc(sizeof(t_room));
		if (!l->room->next)
			free_check_if_room(l, "\033[091mMalloc error\033[0m");
		l->room = l->room->next;
	}
	l->room->name = ft_strdup(array[0]);
	l->room->id = l->id;
	l->id++;
	l->room->next = NULL;
	check_command_rooms(l);
	l->nb_rooms++;
}

int			check_if_room(char *str, t_lemin *l)
{
	char	**array;

	array = NULL;
	check_begin_with_l(str, l);
	check_is_print(str, l);
	array = ft_strsplit(str, ' ');
	if (array == NULL || array[0] == NULL || array[1] == NULL || array[2] == NULL)
		free_check_if_room(l,
			"\033[091mError while retrieving a room\033[0m");
	check_coordonates(array, l);
	check_for_hyphen(array, l);
	check_if_name_already_exists(array, l);
	stock_room_name(l, array);
	ft_free_double_array((void**)array);
	return (0);
}
