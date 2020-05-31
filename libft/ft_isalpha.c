











#include "includes/libft.h"

int	ft_isalpha(int c)
{
	if (ft_islower(c) == 1 || ft_isupper(c) == 1)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
