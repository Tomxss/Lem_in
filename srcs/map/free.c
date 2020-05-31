











#include "../../includes/lem_in.h"

void	free_lst_name(t_lemin *l)
{
	t_room	*temp;

	temp = NULL;
	while (l->begin)
	{
		temp = l->begin;
		l->begin = l->begin->next;
		ft_memdel((void**)&temp->name);
		ft_memdel((void**)&temp);
	}
}

void	free_pipes(t_lemin *l, char *str)
{
	free(l->string_file);
	ft_free_double_array((void**)l->f);
	free_lst_name(l);
	ft_free_double_array((void**)l->dup);
	ft_free_double_array((void**)l->pipes);
	print_error(ft_putendl_fd, str, STDERR_FILENO, l);
}

void	free_check_if_room(t_lemin *l, char *str)
{
	free(l->string_file);
	ft_free_double_array((void**)l->f);
	free_lst_name(l);
	print_error(ft_putendl_fd, str, STDERR_FILENO, l);
}
