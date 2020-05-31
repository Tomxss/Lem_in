











#include "../../includes/lem_in.h"

void	map_start_end_exists(t_lemin *l)
{
	if (ft_strstr(l->string_file, "##start") == 0)
	{
		ft_free_double_array((void**)l->f);
		ft_memdel((void**)&l->string_file);
		print_error(&ft_putendl_fd,
			"\033[091mError: No command given ##start\033[0m",
			STDERR_FILENO, l);
	}
	if (ft_strstr(l->string_file, "##end") == 0)
	{
		ft_free_double_array((void**)l->f);
		ft_memdel((void**)&l->string_file);
		print_error(&ft_putendl_fd,
			"\033[091mError : No command given ##end\033[0m",
			STDERR_FILENO, l);
	}
}
