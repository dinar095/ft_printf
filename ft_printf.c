#include <stdio.h>


#include "libft/libft.h"
#include "ft_printf.h"
/*--------------Function Flags------------------------------------------------*/

int 	ft_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	return (1);
}
int wide_proc(int wide, char **d, char sym, int reverse) //возвращает строку с 0 спереди| В wide подать с учетом знака
{
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
int		int_function(p_list **list, int x)
{
	int		len;
	int 	count;
	char	*tmp;
	char	*tmp2;

	count = 0;

	if ((*list)->precision == 0 && x == 0)
	{
		while ((*list)->wide)
		{
			count += ft_putchar(' ');
			((*list)->wide)--;
		}
		return (count);
	}
	if ((*list)->precision >= 0 && (*list)->flag == 1)
		(*list)->flag = 0;
	if (x < 0 && x != -2147483648)
	{
		(*list)->minus = 1;
		(*list)->wide -=1;
		x *= -1;
	}
	tmp = ft_itoa(x);
	len = ft_strlen(tmp);
	if ((*list)->precision > len) //формируем precision
		wide_proc((*list)->precision, &tmp, '0', 0);
	len = ft_strlen(tmp);
	if ((*list)->wide > len)  //формируем wide
	{
		if ((*list)->flag == 1)
		{
			if ((*list)->minus == 1)
			{
				(*list)->minus = 0;
				count += ft_putchar('-');
			}
			wide_proc((*list)->wide, &tmp, '0', 0);
		}
		else if ((*list)->flag == -1)
		{
			wide_proc((*list)->wide, &tmp, ' ', 1);
		}
		else
		{
			if ((*list)->minus == 1)
			{
				(*list)->minus = 0;
				(*list)->wide++;
				tmp2 = tmp;
				tmp = ft_strjoin("-", tmp); //malloc!
				free(tmp2);
			}
			wide_proc((*list)->wide, &tmp, ' ', 0);
		}
	}
	if ((*list)->minus)
		count += ft_putchar('-');
	count += ft_putstr(tmp);
	free(tmp);
	return (count);
}
int		c_function(p_list **list, char x)
{
	int len;
	char *tmp;

	tmp = &x;
	(*list)->precision = 1;
	tmp = ft_strdup(tmp);
	len = ft_strlen(tmp);
	if ((*list)->precision >= 0 && (size_t) ((*list)->precision) > len)
		(*list)->precision = len;
	//сформировать precision
	if ((*list)->precision >= 0 && (*list)->precision < len)
	{
		ft_memset(tmp + (*list)->precision, '\0', 1);
		wide_proc((*list)->precision, &tmp, '0', 0);\

	}
	//сформировать wide
	if ((*list)->wide > ft_strlen(tmp))
	{
		if ((*list)->flag == 1)
			wide_proc((*list)->wide, &tmp, '0', 0);
		else if ((*list)->flag == -1)
			wide_proc((*list)->wide, &tmp, ' ', 1);
		else
			wide_proc((*list)->wide, &tmp, ' ', 0);
	}
	len = ft_putstr(tmp);
	free(tmp);
	return (len);
}
int		str_function(p_list **list, char *x)
{
	int len;
	char *tmp;

	if (!x)
	{
		x = "(null)";
	}
	tmp = ft_strdup(x);
	len = ft_strlen(tmp);
	if ((*list)->precision >= 0 && (size_t) ((*list)->precision) > len)
		(*list)->precision = len;
	//сформировать precision
	if ((*list)->precision >= 0 && (*list)->precision < len)
	{
		ft_memset(tmp + (*list)->precision, '\0', 1);
		wide_proc((*list)->precision, &tmp, '0', 0);

	}
	//сформировать wide
	if ((*list)->wide > ft_strlen(tmp))
	{
		if ((*list)->flag == 1)
			wide_proc((*list)->wide, &tmp, '0', 0);
		else if ((*list)->flag == -1)
			wide_proc((*list)->wide, &tmp, ' ', 1);
		else
			wide_proc((*list)->wide, &tmp, ' ', 0);
	}
	len = ft_putstr(tmp);
	free(tmp);
	return (len);
}
int		ptr_function(p_list **list, unsigned long long x)
{
	int 	count;
	char	*tmp;
	char	*tmp2;

	count = 0;

	if (x)
	{
		if (!(tmp = ft_itoa_uhex(x)))
			return (0);
		tmp2 = tmp;
		if (!(tmp = ft_strjoin("0x", tmp)) && ft_free(&tmp2))
			return (0);
		free(tmp2);

	}
	else
	{
		if ((*list)->precision == 0)
			tmp = ft_strdup("0x");
		else
			tmp = ft_strdup("0x0");
	}
	if ((*list)->wide > ft_strlen(tmp))
	{
		if ((*list)->flag == -1)
			wide_proc((*list)->wide, &tmp, ' ', 1);
		else
			wide_proc((*list)->wide, &tmp, ' ', 0);
	}
	count += ft_putstr(tmp);
	free(tmp);
	return (count);
}
int 	uint_function(p_list **list, unsigned int x)
{
	int		len;
	int 	count;
	char	*tmp;
	char	*tmp2;

	count = 0;

	if ((*list)->precision == 0 && x == 0)
	{
		while ((*list)->wide)
		{
			count += ft_putchar(' ');
			((*list)->wide)--;
		}
		return (count);
	}
	if ((*list)->precision >= 0 && (*list)->flag == 1)
		(*list)->flag = 0;

	tmp = ft_uitoa(x);
	len = ft_strlen(tmp);
	if ((*list)->precision > len) //формируем precision
		wide_proc((*list)->precision, &tmp, '0', 0);
	if ((*list)->wide > len)  //формируем wide
	{
		if ((*list)->flag == 1)
		{
			if ((*list)->minus == 1)
			{
				(*list)->minus = 0;
				count += ft_putchar('-');
			}
			wide_proc((*list)->wide, &tmp, '0', 0);
		}
		else if ((*list)->flag == -1)
			wide_proc((*list)->wide, &tmp, ' ', 1);
		else
		{
			if ((*list)->minus == 1)
			{
				(*list)->minus = 0;
				(*list)->wide++;
				tmp2 = tmp;
				tmp = ft_strjoin("-", tmp); //malloc!
				free(tmp2);
			}
			wide_proc((*list)->wide, &tmp, ' ', 0);
		}
	}
	if ((*list)->minus)
		count += ft_putchar('-');
	count += ft_putstr(tmp);
	free(tmp);
	return (count);
}
int 	x_function(p_list **list, unsigned long long x)
{
	int		len;
	int 	count;
	char	*tmp;
	char	*tmp2;

	count = 0;

	if ((*list)->precision == 0 && x == 0)
	{
		while ((*list)->wide)
		{
			count += ft_putchar(' ');
			((*list)->wide)--;
		}
		return (count);
	}
	if ((*list)->precision >= 0 && (*list)->flag == 1)
		(*list)->flag = 0;

	tmp = ft_itoa_uhex(x);
	len = ft_strlen(tmp);
	if ((*list)->precision > len) //формируем precision
		wide_proc((*list)->precision, &tmp, '0', 0);
	if ((*list)->wide > len)  //формируем wide
	{
		if ((*list)->flag == 1)
			wide_proc((*list)->wide, &tmp, '0', 0);
		else if ((*list)->flag == -1)
			wide_proc((*list)->wide, &tmp, ' ', 1);
		else
		{
			if ((*list)->minus == 1)
			{
				(*list)->minus = 0;
				(*list)->wide++;
				tmp2 = tmp;
				tmp = ft_strjoin("-", tmp); //malloc!
				free(tmp2);
			}
			wide_proc((*list)->wide, &tmp, ' ', 0);
		}
	}
	count += ft_putstr(tmp);
	free(tmp);
	return (count);
}
int 	bx_function(p_list **list, unsigned long long x)
{
	int		len;
	int 	count;
	char	*tmp;
	char	*tmp2;

	count = 0;

	if ((*list)->precision == 0 && x == 0)
	{
		while ((*list)->wide)
		{
			count += ft_putchar(' ');
			((*list)->wide)--;
		}
		return (count);
	}
	if ((*list)->precision >= 0 && (*list)->flag == 1)
		(*list)->flag = 0;

	tmp = ft_hex_big_itoa(x);
	len = ft_strlen(tmp);
	if ((*list)->precision > len) //формируем precision
		wide_proc((*list)->precision, &tmp, '0', 0);
	if ((*list)->wide > len)  //формируем wide
	{
		if ((*list)->flag == 1)
			wide_proc((*list)->wide, &tmp, '0', 0);
		else if ((*list)->flag == -1)
			wide_proc((*list)->wide, &tmp, ' ', 1);
		else
		{
			if ((*list)->minus == 1)
			{
				(*list)->minus = 0;
				(*list)->wide++;
				tmp2 = tmp;
				tmp = ft_strjoin("-", tmp); //malloc!
				free(tmp2);
			}
			wide_proc((*list)->wide, &tmp, ' ', 0);
		}
	}
	count += ft_putstr(tmp);
	free(tmp);
	return (count);
}
int		processor(char **str, p_list *list, va_list ap)
{
	int count;

	count = 0;
	if ((**str == 'd') || (**str == 'i'))
		count += int_function(&list, va_arg(ap, int));
	else if (**str == 's')
		count += str_function(&list, va_arg(ap, char *));
	else if (**str == 'c')
		count += c_function(&list, va_arg(ap, int));
	else if (**str == '%')
		count += str_function(&list,"%");
	else if (**str == 'p')
		count += ptr_function(&list, va_arg(ap, unsigned long long));
	else if (**str == 'x')
		count += x_function(&list, va_arg(ap, unsigned long long));
	else if (**str == 'X')
		count += bx_function(&list, va_arg(ap, unsigned long long));
		else if (**str == 'u')
			count += uint_function(&list, va_arg(ap, unsigned long long));
	else
		return 0;

	(*str)++;
	return (count);
}
void	flags(char **str, p_list **list){
	while (**str == '0' || **str == '-')
	{
		if (**str == '0' && (*list)->flag != -1)
			(*list)->flag = 1;
		if (**str == '-')
			(*list)->flag = -1;
		(*str)++;
	}
}
void 	wide(char **str, p_list **list, va_list ap)
{
	if (**str >= '0' && **str <= '9')
	{
		(*list)->wide = ft_atoi(*str);
		while (**str >= '0' && **str <= '9')
			(*str)++;
	}
	else if (**str == '*')
	{
		(*list)->wide = va_arg(ap, int);
		if ((*list)->wide < 0)
		{
			(*list)->flag = -1;
			(*list)->wide *=-1;
		}
		(*str)++;
	}
}
void 	precision(char **str, p_list **list, va_list ap)
{
	if (**str == '.')
	{
		(*list)->precision = 0;

		(*str)++;
		if (**str >= '0' && **str <= '9')
		{
			(*list)->precision = ft_atoi(*str);
			while (**str >= '0' && **str <= '9')
				(*str)++;
		}
		else if (**str == '*')
		{
			(*list)->precision = va_arg(ap, int);
			(*str)++;
		}
	}
}
void 	reset_list(p_list **list)
{
	(*list)->flag = 0;
	(*list)->wide = 0;
	(*list)->precision = -1;
	(*list)->minus = 0;
}
void	parser(char **str, va_list ap, p_list *list)
{
	if (ft_strchr(ALL_SYMBOLS, **str))
	{
		reset_list(&list);
		if (**str != '\0')                                //возможно надо удалить
		{
			flags(str, &list);
			wide(str, &list, ap);
			precision(str, &list, ap);
		}
	}
}
int		start_function(char *str, va_list ap)
{
	p_list	list;
	int		count;

	count = 0;
	while (*str != '\0')
	{
		while (*str == '%')
		{
			str++;
			parser(&str, ap, &list);
			count += processor(&str, &list, ap);
		}
		if (*str)
		{
			count += ft_putchar(*str);
			str++;
		}
	}
	return (count);
}
int		ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;

	va_start(ap, format);
	count = start_function((char *)format, ap);
	va_end(ap);
	return (count);
}
//
//int main(void)
//{
//	int		a = -4;
//	int		b = 0;
//	char	c = 'a';
//	int		d = 2147483647;
//	int		e = -2147483648;
//	int		f = 42;
//	int		g = 25;
//	int		h = 4200;
//	int		i = 8;
//	int		j = -12;
//	int		k = 123456789;
//	int		l = 0;
//	int		m = -12345678;
////ft_printf("%7.3i, %1d, %1d, %1d, %1d, %1d, %1d, %1d\n", -i, j, k, l, m, c, e, d);
//printf("%0*X\n", 3, j);
//ft_printf("%0*X", 3, j);
//
//	return 0;
//}