
#include "includes/libft.h"

char	*ft_strdup_plus_char(const char *s1, char c)
{
	char	*duplicate;
	int		strlen;
	int		j;

	strlen = ft_strlen_secure(s1);
	j = 0;
	duplicate = (char *)malloc(((unsigned long)strlen + 2) * sizeof(char));
	if (duplicate == NULL)
		return (NULL);
	while (s1[j] != '\0')
	{
		duplicate[j] = s1[j];
		j++;
	}
	duplicate[j] = c;
	duplicate[j + 1] = '\0';
	return (duplicate);
}
