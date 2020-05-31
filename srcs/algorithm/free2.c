











#include "../../includes/lem_in.h"

void	ft_free_array_bool(bool **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		free(array[i++]);
	free(array);
}

void	free_queue(t_queue *lst)
{
	t_queue	*temp;

	temp = NULL;
	while (lst)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
}

void	free_pipes_and_sum(t_lemin *l, char *str)
{
	free(l->sum);
	free(l->string_file);
	ft_free_double_array((void**)l->f);
	free_lst_name(l);
	ft_free_double_array((void**)l->dup);
	ft_free_double_array((void**)l->pipes);
	print_error(ft_putendl_fd, str, STDERR_FILENO, l);
}

void	free_at_end(t_lemin *l)
{
	free(l->sum);
	ft_memdel((void**)&l->string_file);
	ft_free_double_array((void**)l->f);
	ft_free_double_array((void**)l->dup);
	ft_free_double_array((void**)l->pipes);
	l->solution = l->solution_begin;
	free(l->sorted);
	free_lst_name(l);
}

void	free_result(t_lemin *l)
{
	t_room	*path;
	t_room	*temp;
	int		i;

	i = 0;
	path = NULL;
	temp = NULL;
	while (l->result[i] != NULL)
	{
		path = l->result[i];
		while (path)
		{
			temp = path;
			path = path->next;
			free(temp);
		}
		i++;
	}
	free(l->result);
}
