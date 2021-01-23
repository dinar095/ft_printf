/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qx_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desausag <desausag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:29:35 by desausag          #+#    #+#             */
/*   Updated: 2021/01/23 21:33:14 by desausag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		qx_function(t_list *strct, unsigned int x, int flag)
{
	int		count;
	char	*tmp;
	char	*tmp2;

	count = 0;
	if (strct->precision == 0 && x == 0)
	{
		while ((strct->wide)--)
			count += ft_putchar(' ');
		return (count);
	}
	if (strct->precision >= 0 && strct->flag == 1)
		strct->flag = 0;
	tmp = ft_itoa_uhex(x);
	if (strct->precision > (int)ft_strlen(tmp))
		wide_proc(strct->precision, &tmp, '0', 0);
	count += p_wide(strct, &tmp);
	tmp2 = tmp;
	while (flag && *tmp2 != '\0')
	{
		*tmp2 = ft_toupper(*tmp2);
		tmp2++;
	}
	count += ft_putstr(tmp);
	return (count * ft_free(&tmp));
}
