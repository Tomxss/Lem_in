











#include "includes/libft.h"

char	*ft_fill_with(size_t size, char c)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * size + 1);
	str[size + 1] = '\0';
	while (i <= size)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
