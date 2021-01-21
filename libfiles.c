#include "ft_printf.h"
#include <string.h>
#include <unistd.h>

void 	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar(*s++);
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
void	*ft_strset(void *destination, int c, size_t n)
{
	unsigned char	*b;
	size_t			i;

	i = 0;
	b = (unsigned char *)destination;
	while (i != n)
	{
		b[i++] = c;
	}
	b[i] = '\0';
	return (destination);
}