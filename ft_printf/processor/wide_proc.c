/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desausag <desausag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:46:32 by desausag          #+#    #+#             */
/*   Updated: 2021/01/23 21:19:54 by desausag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		wide_proc(int wide, char **d, char sym, int reverse)
{
	char	*tmp0;
	int		cint;

	tmp0 = ft_calloc(wide + 1, sizeof(char));
	ft_strset(tmp0, sym, wide);
	cint = ft_strlen(*d);
	wide -= cint;
	if (!reverse)
		ft_memcpy(tmp0 + wide, *d, cint);
	else
		ft_memcpy(tmp0, *d, cint);
	free(*d);
	*d = tmp0;
	return (ft_strlen(tmp0));
}
