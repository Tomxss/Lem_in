











#include "includes/libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(dst);
	len_dest = i;
	if (len_dest > size)
		len_dest = size;
	while (src[j] != '\0' && (int)(size-- - len_dest - 1) > 0)
	{
		dst[i + j] = src[j];
		j++;
	}
	len_src = ft_strlen(src);
	dst[i + j] = '\0';
	return (len_dest + len_src);
}
