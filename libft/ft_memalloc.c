











#include "includes/libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*memory;

	memory = malloc(size * sizeof(void *));
	if (memory == 0)
		return (0);
	ft_bzero(memory, size);
	return (memory);
}
