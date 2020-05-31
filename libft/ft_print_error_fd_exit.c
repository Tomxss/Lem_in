











#include "includes/libft.h"

void	ft_print_error_fd_exit(void (*function)(const char *, int fd),
		const char *str, int fd)
{
	(*function)(str, fd);
	exit(1);
}
