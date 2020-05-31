











#include "includes/libft.h"

void	ft_print_error_exit(void (*function)(const char *), const char *str)
{
	(*function)(str);
	exit(1);
}
