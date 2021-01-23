/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desausag <desausag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:35:18 by desausag          #+#    #+#             */
/*   Updated: 2021/01/23 21:40:05 by desausag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		str_function(t_list *strct, char *x)
{
	int		len;
	char	*tmp;

	if (!x)
		x = "(null)";
	tmp = ft_strdup(x);
	len = ft_strlen(tmp);
	if (strct->precision >= 0 && (strct->precision) > len)
		strct->precision = len;
	if (strct->precision >= 0 && strct->precision < len)
	{
		ft_memset(tmp + strct->precision, '\0', 1);
		wide_proc(strct->precision, &tmp, '0', 0);
	}
	if (strct->wide > (int)ft_strlen(tmp))
	{
		if (strct->flag == 1)
			wide_proc(strct->wide, &tmp, '0', 0);
		else if (strct->flag == -1)
			wide_proc(strct->wide, &tmp, ' ', 1);
		else
			wide_proc(strct->wide, &tmp, ' ', 0);
	}
	len = ft_putstr(tmp);
	return (len * ft_free(&tmp));
}
