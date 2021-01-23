/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desausag <desausag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:32:27 by desausag          #+#    #+#             */
/*   Updated: 2021/01/23 21:31:41 by desausag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		uint_function(t_list *strct, unsigned int x)
{
	int		len;
	int		count;
	char	*tmp;

	count = 0;
	if (strct->precision == 0 && x == 0)
	{
		while ((strct->wide)--)
			count += ft_putchar(' ');
		return (count);
	}
	if (strct->precision >= 0 && strct->flag == 1)
		strct->flag = 0;
	tmp = ft_uitoa(x);
	len = ft_strlen(tmp);
	if (strct->precision > len)
		wide_proc(strct->precision, &tmp, '0', 0);
	count += p_wide(strct, &tmp);
	if (strct->minus)
		count += ft_putchar('-');
	count += ft_putstr(tmp);
	return (count * ft_free(&tmp));
}
