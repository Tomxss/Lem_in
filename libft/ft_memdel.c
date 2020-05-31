











#include "includes/libft.h"
#include <stdlib.h>

void	ft_memdel(void **ap)
{
	if (ap != 0)
	{
		free(*ap);
		*ap = 0;
	}
}
