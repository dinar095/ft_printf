#include <stdio.h>


#include "lib/libft.h"
#include "ft_printf.h"

void d_function(char *str, va_list ap)
{
	int x;
	x = va_arg(ap, int);
	printf("%d", x);
}
void s_function(char *str, va_list ap)
{
	char *x;
	x = va_arg(ap, char *);
	printf("%s", x);
}
/*--------------Function Flags------------------------------------------------*/
void	parser(char **str, va_list ap)
{
	p_list	*list;
	if (!(list = (p_list *)malloc(sizeof(p_list))))
		printf("ERROR MEMORY");											//**** del prinft

	if (**str == '%')
	{

		ft_putchar(**str);
		str++;

	}
	else if (ft_strchr(ALL_SYMBOLS, **str))
	{

	}
}
void start_function(char *str, va_list ap)
{

	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			parser(&str, ap);
		}
		ft_putchar(*str);
		str++;
	}
}

void ft_printf(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	start_function((char *)format, ap);
	va_end(ap);
}
int main(void)
{
char *s = "Heloooo";
//char *p = &s[3];
ft_printf("text before %%%strtr\n", "Hello", "/bls|");
//printf("text before %%%strtr", "Hello");
//ft_putstr(&s, (p - s));
//printf("\n%-10.5d\n", 589);
	return 0;
}