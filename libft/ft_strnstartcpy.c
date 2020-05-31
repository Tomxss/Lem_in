











#include "includes/libft.h"

char	*ft_strnstartcpy(char *s, size_t i)
{
	size_t	len;
	char	*str;
	size_t	j;

	str = NULL;
	len = ft_strlen(s) - i;
	j = 0;
	str = malloc(sizeof(char) * len + 1);
	while (s[i] != '\0')
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
