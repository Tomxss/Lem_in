











#include "includes/libft.h"

int		**ft_create_array(unsigned long x, unsigned long y)
{
	int		**array;
	int		i;
	int		j;

	array = NULL;
	i = 0;
	j = 0;
	array = (int **)malloc(sizeof(int *) * (y + 1));
	if (array == NULL)
		return (NULL);
	while ((unsigned long)i < y)
	{
		array[i] = (int *)malloc(sizeof(int) * x);
		if (array[i] == NULL)
		{
			ft_free_double_array((void**)array);
			return (NULL);
		}
		while ((unsigned long)j < x)
			array[i][j++] = '\0';
		j = 0;
		i++;
	}
	array[i] = NULL;
	return (array);
}
