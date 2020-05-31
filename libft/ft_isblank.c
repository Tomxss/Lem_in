











#include "includes/libft.h"

int	ft_isblank(int c)
{
	if (c == 9 || c == 32)
		return (1);
	else
		return (0);
}
