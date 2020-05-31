











#include "includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	int		j;
	size_t	size_little;

	i = 0;
	j = 0;
	size_little = (size_t)ft_strlen(little);
	if (little[i] == '\0')
	{
		return ((char *)big);
	}
	while (big[i] != '\0' && len >= size_little)
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			j++;
			if (little[j] == '\0')
				return ((char*)&big[i]);
		}
		i++;
		len--;
	}
	return (0);
}
