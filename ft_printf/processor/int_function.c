/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desausag <desausag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:45:27 by desausag          #+#    #+#             */
/*   Updated: 2021/01/24 09:50:53 by desausag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	func_for_zero(t_list *strct, char **tmp)
{
	char *tmp2;

	strct->minus = 0;
	strct->wide++;
	tmp2 = *tmp;
	if(!(*tmp = ft_strjoin("-", *tmp)))
		return (0);
	free(tmp2);
	return (1);
}

int			p_wide(t_list *strct, char **tmp)
{
	int count;

	count = 0;
	if (strct->wide > (int)ft_strlen(*tmp))
	{
		if (strct->flag == 1)
		{
			if (strct->minus == 1)
			{
				strct->minus = 0;
				count += ft_putchar('-');
			}
			wide_proc(strct->wide, tmp, '0', 0);
		}
		else if (strct->flag == -1)
			wide_proc(strct->wide, tmp, ' ', 1);
		else
		{
			if (strct->minus == 1)
				func_for_zero(strct, tmp);
			wide_proc(strct->wide, tmp, ' ', 0);
		}
	}
	return (count);
}

static int	minus_func(t_list *strct)
{
	strct->minus = 1;
	strct->wide -= 1;
	return (-1);
}

int			int_function(t_list *strct, int x)
{
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
	if (x < 0 && x != -2147483648)
		x *= minus_func(strct);
	tmp = ft_itoa(x);
	if (strct->precision > (int)ft_strlen(tmp))
		wide_proc(strct->precision, &tmp, '0', 0);
	count += p_wide(strct, &tmp);
	if (strct->minus)
		count += ft_putchar('-');
	count += ft_putstr(tmp);
	return (count * ft_free(&tmp));
}
