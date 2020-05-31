











#include "includes/libft.h"
#include <stdlib.h>

int	ft_lstsize(t_list *begin_list)
{
	int		i;
	t_list	*test;

	test = begin_list;
	i = 0;
	while (test != NULL)
	{
		test = test->next;
		i++;
	}
	return (i);
}
