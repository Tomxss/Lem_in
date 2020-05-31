











#include "includes/libft.h"

int		ft_binary_to_decimal(char *str)
{
	int		i;
	int		nb;
	int		power;
	int		binary;
	int		number;

	if (str == NULL)
		str = NULL;
	i = 0;
	nb = 0;
	binary = 2;
	power = 7;
	while (power >= 0)
	{
		if (str[i] == '1')
			number = 1;
		else
			number = 0;
		nb = nb + number * ft_nb_power_nb(2, power);
		power--;
		i++;
	}
	return (nb);
}
