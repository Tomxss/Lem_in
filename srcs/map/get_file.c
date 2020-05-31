











#include "../../includes/lem_in.h"

static void	get_raw_data(t_lemin *l)
{
	l->string_file = ft_read_all_file(STDIN_FILENO);
	if (l->string_file == NULL)
		print_error(&ft_putendl_fd,
				"\033[091mError reading file\033[0m",
				STDERR_FILENO, l);
}

static void	get_formatted_file(t_lemin *l)
{
	l->f = ft_strsplit_strict(l->string_file, '\n');
	if (l->f == NULL)
	{
		ft_memdel((void**)&l->string_file);
		print_error(ft_putendl_fd,
			"\033[091mError: Invalid file\033[0m", STDERR_FILENO, l);
	}
}

void		handle_file(t_lemin *l)
{
	get_raw_data(l);
	get_formatted_file(l);
}
