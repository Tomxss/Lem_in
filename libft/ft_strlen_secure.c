











#include "includes/libft.h"

size_t	ft_strlen_secure(const char *s)
{
	if (s == NULL)
		return (0);
	else
		return (ft_strlen(s));
}
