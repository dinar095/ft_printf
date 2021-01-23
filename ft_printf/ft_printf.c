/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desausag <desausag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:47:13 by desausag          #+#    #+#             */
/*   Updated: 2021/01/23 22:18:46 by desausag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		start_function(char *str, va_list ap)
{
	t_list	strct;
	int		count;

	count = 0;
	while (*str != '\0')
	{
		while (*str == '%')
		{
			str++;
			parser(&str, ap, &strct);
			count += processor(&str, &strct, ap);
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
