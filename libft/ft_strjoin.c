











#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;

	if (s2 == 0 || s1 == 0)
		return (0);
	new_str = ft_strnew(ft_strlen_secure(s1) + ft_strlen_secure(s2));
	if (new_str == 0)
		return (0);
	else
	{
		ft_strcpy(new_str, s1);
		ft_strcat(new_str, s2);
		return (new_str);
	}
}
