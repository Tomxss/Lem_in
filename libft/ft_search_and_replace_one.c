











#include "includes/libft.h"

char	*search_and_replace_one(char *str, char *old, char *new)
{
	size_t	oldlen;
	size_t	newlen;
	char	*new_str;
	char	*temp;
	size_t	char_begin;

	char_begin = 0;
	oldlen = ft_strlen_secure(str);
	newlen = oldlen - (ft_strlen_secure(old) - ft_strlen_secure(new));
	new_str = ft_strnew(newlen);
	temp = ft_strstr(str, old);
	char_begin = ft_strlen_secure(str) - ft_strlen_secure(temp);
	new_str = ft_strncpy(new_str, str, char_begin);
	new_str = ft_strcat(new_str, new);
	temp = temp + ft_strlen_secure(old);
	new_str = ft_strcat(new_str, temp);
	return (new_str);
}
