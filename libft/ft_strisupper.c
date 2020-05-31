











#include "includes/libft.h"

int		ft_strisupper(char *str)
{
	int		i;
	int		mark;

	i = 0;
	mark = 1;
	while (str[i] != '\0')
	{
		if ((ft_isupper(str[i++])) == 0)
			mark = 0;
	}
	if (mark == 0)
		return (0);
	else
		return (1);
}
