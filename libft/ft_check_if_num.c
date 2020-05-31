











#include "includes/libft.h"

int	ft_check_if_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i++]) == 0)
			return (1);
	}
	return (0);
}
