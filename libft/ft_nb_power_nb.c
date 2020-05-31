











#include "includes/libft.h"

int		ft_nb_power_nb(int nb, int power)
{
	int	result;

	result = nb;
	if (power == 0)
		return (1);
	else if (power == 1)
		return (nb);
	while (power > 1)
	{
		result = result * nb;
		power--;
	}
	return (result);
}
