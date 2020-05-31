











#include "includes/libft.h"

int	ft_isprint(int c)
{
	if ((unsigned int)c >= ' ' && (unsigned int)c <= '~')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
