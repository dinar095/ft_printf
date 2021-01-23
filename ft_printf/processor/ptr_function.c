/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desausag <desausag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:33:53 by desausag          #+#    #+#             */
/*   Updated: 2021/01/23 21:44:53 by desausag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

static void		rer(char **tmp)
{
	char	*tmp2;

	tmp2 = *tmp;
	*tmp = ft_strjoin("0x", *tmp);
	free(tmp2);
}

int				ptr_function(t_list *strct, long unsigned int x)
{
	int		count;
	char	*tmp;

	if (x)
	{
		tmp = ft_itoa_uhex(x);
		rer(&tmp);
	}
	else
	{
		if (strct->precision == 0)
			tmp = ft_strdup("0x");
		else
			tmp = ft_strdup("0x0");
	}
	if (strct->wide > (int)ft_strlen(tmp))
	{
		if (strct->flag == -1)
			wide_proc(strct->wide, &tmp, ' ', 1);
		else
			wide_proc(strct->wide, &tmp, ' ', 0);
	}
	count = ft_putstr(tmp);
	return (count * ft_free(&tmp));
}
