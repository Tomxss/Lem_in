











#include "includes/libft.h"

void	ft_putwstr(wchar_t *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putwchar(str[i]);
		i++;
	}
}
