











#include "includes/libft.h"

void	ft_swap_adress(char **a, char **b)
{
	char	*c;

	c = 0;
	c = *a;
	*a = *b;
	*b = c;
}
