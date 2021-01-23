/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desausag <desausag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:24:29 by desausag          #+#    #+#             */
/*   Updated: 2021/01/23 21:27:49 by desausag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

int		processor(char **str, t_list *strct, va_list ap)
{
	int count;

	count = 0;
	if ((**str == 'd') || (**str == 'i'))
		count += int_function(strct, va_arg(ap, int));
	else if (**str == 's')
		count += str_function(strct, va_arg(ap, char *));
	else if (**str == 'c')
		count += c_function(strct, va_arg(ap, int));
	else if (**str == '%')
		count += str_function(strct, "%");
	else if (**str == 'p')
		count += ptr_function(strct, va_arg(ap, long unsigned int));
	else if (**str == 'x')
		count += qx_function(strct, va_arg(ap, unsigned int), 0);
	else if (**str == 'X')
		count += qx_function(strct, va_arg(ap, unsigned int), 1);
	else if (**str == 'u')
		count += uint_function(strct, va_arg(ap, unsigned long long));
	else
		return (0);
	(*str)++;
	return (count);
}
