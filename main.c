#include <stdio.h>


#include "lib/libft.h"
#include "ft_printf.h"
/*--------------Function Flags------------------------------------------------*/
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
//flags function
void	flags(char **str, p_list *list)//флаги
{

		while (**str == '0' || **str == '-')
		{
			if (**str == '0')
				list->flag = 0;
			else if (**str == '-')
				list->flag = -1;
			(*str)++;
		}
}
//wide function
void 	wide(char **str, p_list *list, va_list ap)
{
	if (**str > '0' && **str <= '9')
	{
		list->wide = ft_atoi(*str);
		while (**str > '0' && **str <= '9')
			(*str)++;
	}
	else if (**str == '*')
	{
		list->wide = va_arg(ap, int);
		(*str)++;
	}
}
void 	precision(char **str, p_list *list, va_list ap)
{
	if (**str == '.')
	{
		list->precision = 0;
		(*str)++;
		if (**str > '0' && **str <= '9')
		{
			list->precision = ft_atoi(*str);
			while (**str > '0' && **str <= '9')
				(*str)++;
		}
		else if (**str == '*')
		{
			list->precision = va_arg(ap, int);
		}
	}
}
// Precision function
void	parser(char **str, va_list ap)
{
	p_list	*list;

	if (**str == '%')//Если встретился повторный %
	{
		ft_putchar(**str);
		(**str)++;
		return;
	}
	if (ft_strchr(ALL_SYMBOLS, **str))
	{
		//выделяю память под лист
		if (!(list = (p_list *)malloc(sizeof(p_list))))
			printf("ERROR MEMORY");											//**** del prinft
			
		while (**str != '\0' && **str != '%' && **str !='d')                                //возможно надо удалить
		{
			flags(str, list);
			wide(str, list, ap);
			precision(str, list, ap);


		}
	}
//			else if (ft_strchr("ALLNUMS", **str))//--------------------------------
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
ft_printf("text before %-*.45dyhy\n", 20, "Hello", "/bls|");
//printf("text before %%%strtr", "Hello");
//ft_putstr(&s, (p - s));
//printf("\n%*60.50d\n", 100, 589);
	return 0;
}