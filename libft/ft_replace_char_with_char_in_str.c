











#include "includes/libft.h"

void	ft_replace_char_with_char_in_str(char **str, char search, char replace)
{
	int		i;

	i = 0;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == search)
			(*str)[i++] = replace;
		else
			i++;
	}
}
