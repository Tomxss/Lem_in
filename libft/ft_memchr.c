











#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	if (n != 0)
	{
		while (i < n)
		{
			if (str[i] == (char)c)
				return ((void*)&str[i]);
			i++;
		}
	}
	return (0);
}
