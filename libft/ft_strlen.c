











#include "includes/libft.h"

size_t	ft_strlen_min(const char *s)
{
	size_t i;

	i = 0;
	if (s[i] == '-')
		i--;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
