











#include "includes/libft.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n > -2147483648 && n <= -10)
	{
		ft_putchar('-');
		n = n * -1;
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else if (n < 0 && n > -10)
	{
		ft_putchar('-');
		ft_putchar((char)-n + '0');
	}
	else if (n >= 0 && n <= 9)
	{
		ft_putchar((char)n + '0');
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
