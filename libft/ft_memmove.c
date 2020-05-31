











#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;

	dest = (char *)dst;
	source = (const char *)src;
	if (dest || source || len)
	{
		if (dest <= source)
			ft_memcpy(dest, source, len);
		else
		{
			if (len == 0)
				return (dest);
			while (len > 0)
			{
				dest[len - 1] = source[len - 1];
				len--;
			}
		}
	}
	return (dst);
}
