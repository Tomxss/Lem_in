











#include "includes/libft.h"

int		count_idem_char(char *str, const char *old, int *count,
		int old_len)
{
	int		i;

	i = 0;
	while (str[i++] != '\0')
	{
		if (ft_strstr(&str[i], old) == &str[i])
		{
			count++;
			i = i + old_len - 1;
		}
	}
	return (i);
}

char	*search_and_replace_all(char *str, const char *old, const char *new)
{
	char	*new_str;
	int		i;
	int		count;
	int		new_len;
	int		old_len;

	count = 0;
	new_len = (int)ft_strlen(new);
	old_len = (int)ft_strlen(old);
	i = count_idem_char(str, old, &count, old_len);
	new_str = ft_strnew((unsigned long)i + (size_t)count *
			(unsigned long)(new_len - old_len));
	i = 0;
	while (*str)
	{
		if (ft_strstr(str, old) == str)
		{
			ft_strcpy(&new_str[i], new);
			i = i + new_len;
			str = str + old_len;
		}
		else
			new_str[i++] = *str++;
	}
	return (new_str);
}
