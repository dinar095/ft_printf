#include <stdio.h>


#include "lib/libft.h"
#include "ft_printf.h"
/*--------------Function Flags------------------------------------------------*/
void	int_function(p_list *list, int x)
{
	int c;
	int i;

	c = x;
	i = 0;
	if (list->precision == 0 && x == 0)
	{
		while (list->wide)
		{
			ft_putchar(' ');
			(list->wide)--;
		}
	}

	if (list->precision > 0)
	{
		if (x < 0 && x != -2147483648)
		{
			ft_putchar('-');
			x *= -1;
		}
		while (c / 10)
			i++;
		list->precision -= i;
		while (--list->precision > 0)
			ft_putchar('0');
	}

	ft_putnbr(x);
}
void	str_function(p_list *list, char *x)
{
	while (*x != '\0')
	{
		ft_putchar(*x);
		x++;

	}
}
void	processor(char **str, p_list *list, va_list ap)
{
	if (ft_strchr("dis", **str))
	{
		if ((**str == 'd') || (**str == 'i'))
			int_function(list, va_arg(ap, int));
		else if (**str == 's')
			str_function(list, va_arg(ap, char *));
//		else if (**str == 'c')
//			char_function(list, ap);
//		else if (**str == 'p')
//			ptr_function(list, ap);
//		else if (**str == 'x')
//			hex_function(list, ap);
//		else if (**str == 'X')
//			hex_function(list, ap);
//		else if (**str == 'u')
//			uint_function(list, ap);
		(*str)++;
	}
}
void	flags(char **str, p_list *list){
	while (**str == '0' || **str == '-')
	{
		if (**str == '0')
			list->flag = 1;
		if (**str == '-')
			list->flag = -1;
		(*str)++;
	}
}
void 	wide(char **str, p_list *list, va_list ap)
{
	if (**str >= '0' && **str <= '9')
	{
		list->wide = ft_atoi(*str);
		while (**str > '0' && **str <= '9')
			(*str)++;
	}
	else if (**str == '*')
	{
		list->wide = va_arg(ap, int);
		if (list->wide < 0)
		{
			list->flag = -1;
			list->wide *=-1;
		}
		(*str)++;
	}
}
void 	precision(char **str, p_list *list, va_list ap)
{
	if (**str == '.')
	{
		list->precision = 0;
		(*str)++;
		if (**str >= '0' && **str <= '9')
		{
			list->precision = ft_atoi(*str);
			while (**str >= '0' && **str <= '9')
				(*str)++;
		}
		else if (**str == '*')
		{
			list->precision = va_arg(ap, int);
		}
	}
}
void 	reset_list(p_list *list)
{
	list->flag = 0;
	list->wide = 0;
	list->precision = -1;
	list->minus = 0;
}
p_list	*parser(char **str, va_list ap)
{
	p_list	*list;

	if (**str == '%')//Если встретился повторный %
	{
		ft_putchar(**str);
		(**str)++;
		return (0);
	}
	if (ft_strchr(ALL_SYMBOLS, **str))
	{
		//выделяю память под лист
		if (!(list = (p_list *)malloc(sizeof(p_list))))
			printf("ERROR MEMORY");										//**** del prinft
		reset_list(list);
			
		if (**str != '\0')                                //возможно надо удалить
		{
			flags(str, list);
			wide(str, list, ap);
			precision(str, list, ap);
		}
	}
	return (list);
}
void	start_function(char *str, va_list ap)
{
	p_list *list;

	while (*str != '\0')
	{
		while (*str == '%')
		{
			str++;
			list = parser(&str, ap);
			processor(&str, list, ap);
		}
		ft_putchar(*str);
		str++;
	}
}
int		ft_printf(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	start_function((char *)format, ap);
	va_end(ap);
	return 0;
}

int main(void)
{
	char *s = "Heloooo";
//char *p = &s[3];
ft_printf("%0.3i\n", -8);
//printf("text before %%%strtr", "Hello");
//ft_putstr(&s, (p - s));
printf("%-5.3d\n", -8);
	return 0;
}