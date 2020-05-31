











#include "includes/libft.h"

void	ft_free_double_array(void **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		free(array[i++]);
	free(array);
}
