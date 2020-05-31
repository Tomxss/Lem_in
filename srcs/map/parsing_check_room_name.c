











#include "../../includes/lem_in.h"

void	check_for_hyphen(char **array, t_lemin *l)
{
	if (ft_strchr(array[0], '-') != 0)
	{
		ft_free_double_array((void**)array);
		free_check_if_room(l,
			"\033[091mError: A room name cannot contain a dash\
			\033[0m");
	}
}

void	check_if_name_already_exists(char **array, t_lemin *l)
{
	t_room *temp;

	temp = l->begin;
	while (temp != NULL)
	{
		if (ft_strcmp(temp->name, array[0]) == 0)
		{
			ft_free_double_array((void**)array);
			free_check_if_room(l,
			"\033[091mError: A room name must be unique\033[0m");
		}
		temp = temp->next;
	}
}

void	check_begin_with_l(char *str, t_lemin *l)
{
	if (str[0] && str[0] == 'L')
		free_check_if_room(l,
			"\033[091mError: A room name cannot start with 'L'\
			\033[0m");
}

void	check_is_print(char *str, t_lemin *l)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isprint(str[i]) == 0)
			flag = 1;
		i++;
	}
	if (flag == 1)
		free_check_if_room(l,
			"\033[091mError: One or more room names are invalid\
			\033[0m");
}
