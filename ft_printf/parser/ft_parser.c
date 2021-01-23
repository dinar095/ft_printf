/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desausag <desausag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 13:48:59 by desausag          #+#    #+#             */
/*   Updated: 2021/01/23 22:07:51 by desausag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		flags(char **str, t_list *strct)
{
	while (**str == '0' || **str == '-')
	{
		if (**str == '0' && strct->flag != -1)
			strct->flag = 1;
		if (**str == '-')
			strct->flag = -1;
		(*str)++;
	}
}

static void		wide(char **str, t_list *strct, va_list ap)
{
	if (**str >= '0' && **str <= '9')
	{
		strct->wide = ft_atoi(*str);
		while (**str >= '0' && **str <= '9')
			(*str)++;
	}
	else if (**str == '*')
	{
		strct->wide = va_arg(ap, int);
		if (strct->wide < 0)
		{
			strct->flag = -1;
			strct->wide *= -1;
		}
		(*str)++;
	}
}

static void		precision(char **str, t_list *strct, va_list ap)
{
	if (**str == '.')
	{
		strct->precision = 0;
		(*str)++;
		if (**str >= '0' && **str <= '9')
		{
			strct->precision = ft_atoi(*str);
			while (**str >= '0' && **str <= '9')
				(*str)++;
		}
		else if (**str == '*')
		{
			strct->precision = va_arg(ap, int);
			(*str)++;
		}
	}
}

static void		reset_list(t_list *strct)
{
	strct->flag = 0;
	strct->wide = 0;
	strct->precision = -1;
	strct->minus = 0;
}

void			parser(char **str, va_list ap, t_list *strct)
{
	if (ft_strchr(ALL_SYMBOLS, **str))
	{
		reset_list(strct);
		if (**str != '\0')
		{
			flags(str, strct);
			wide(str, strct, ap);
			precision(str, strct, ap);
		}
	}
}
