











#include "../../includes/lem_in.h"

void	print_error(void (*function)(const char *, int fd),
		const char *str, int fd, t_lemin *l)
{
	if (l->debug == 1)
	{
		(*function)(str, fd);
		exit(1);
	}
	else
	{
		ft_putendl_fd("ERROR", STDOUT_FILENO);
		exit(1);
	}
}
