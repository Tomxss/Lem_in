











#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s != 0 && f != 0)
	{
		new_str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
		if (new_str == 0)
			return (0);
		while (s[i] != '\0')
		{
			new_str[j] = f(s[i]);
			i++;
			j++;
		}
		new_str[j] = '\0';
		return (new_str);
	}
	return (0);
}
