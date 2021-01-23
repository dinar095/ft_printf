/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_function.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desausag <desausag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:36:23 by desausag          #+#    #+#             */
/*   Updated: 2021/01/23 21:32:47 by desausag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		c_function(t_list *strct, char x)
{
	char count;

	count = 1;
	while (strct->wide && strct->flag == 1)
	{
		write(1, "0", 1);
		count++;
		strct->wide--;
	}
	while ((--strct->wide > 0 && strct->flag != -1))
	{
		write(1, " ", 1);
		count++;
	}
	write(1, &x, 1);
	while (strct->wide > 0 && strct->flag == -1)
	{
		write(1, " ", 1);
		count++;
		strct->wide--;
	}
	return (count);
}
