#include <stdio.h>


#include "lib/libft.h"
#include "ft_printf.h"
/*--------------Function Flags------------------------------------------------*/


int wide_proc(int wide, char **d, char sym, int reverse) //возвращает строку с 0 спереди| В wide подать с учетом знака
{
	// wp - wide or precision
	char 	*tmp;
	int 	cint;
	tmp = ft_calloc(wide, sizeof(char)); //создать строку
	ft_strset(tmp, sym, wide); //забить всю строку символом с
	cint = ft_strlen(*d);//длина числа без -
	wide -= cint;
	if (!reverse)
		ft_memcpy(tmp + wide, *d, cint);//добавить число в конце
	else
		ft_memcpy(tmp, *d, cint); //добавить число в начале
	free(*d);
	*d = tmp;
	return (ft_strlen(tmp));
}
void	int_function(p_list *list, int x)
{
	int c;
	int len;
	char *tmp;

	c = 0;
	if (list->precision == 0 && x == 0)
	{
		while (list->wide)
		{
			ft_putchar(' ');
			(list->wide)--;
		}
	}
	if (x < 0 && x != -2147483648)
	{
		list->minus = 1;
		list->wide -=1;
		x *= -1;
	}
	tmp = ft_itoa(x);
	len = ft_strlen(tmp);
	if (list->precision > len) //формируем precision
	{
		c = wide_proc(list->precision, &tmp, '0', 0);
	}
	if (list->wide > c)
	{
		if (list->flag == 1)
		{
			if (list->minus == 1)
			{
				list->minus = 0;
				ft_putchar('-');
			}
			c = wide_proc(list->wide, &tmp, '0', 0);
		}
		else if (list->flag == -1)
		{
			c = wide_proc(list->wide, &tmp, ' ', 1);
		}
		else
		{
			if (list->minus == 1)
			{
				list->minus = 0;
				list->wide++;
				tmp = ft_strjoin("-", tmp); //malloc!
			}
			c = wide_proc(list->wide, &tmp, ' ', 0);
		}
	}
	if (list->minus)
		ft_putchar('-');
	ft_putstr(tmp);
	free(tmp);
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
		while (**str >= '0' && **str <= '9')
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
		if (list->flag == 1)
			list->flag = 0;
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
ft_printf("%9.7d\n", -123456);
//printf("text before %%%strtr", "Hello");
//ft_putstr(&s, (p - s));
printf("%9.7d\n", -123456);
	return 0;
}