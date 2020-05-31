











#include "includes/libft.h"

void	ft_strclr(char *s)
{
	if (s != 0)
		ft_bzero(s, ft_strlen(s));
}
