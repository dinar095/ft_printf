#include "ft_printf.h"
#include <string.h>
#include <unistd.h>

void 	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putnbr(int n)
{
	int i;

	i = n % 10 < 0 ? -1 : 1;
	if (n / 10)
		ft_putnbr(n / 10);
	else if (n < 0)
		ft_putchar('-');
	ft_putchar((n % 10) * i + '0');
}