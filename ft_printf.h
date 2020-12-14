/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desausag <desausag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:15:50 by desausag          #+#    #+#             */
/*   Updated: 2020/12/14 14:54:38 by desausag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DESAUSAG_FT_PRINTF_H
# define DESAUSAG_FT_PRINTF_H

#include <stdarg.h>
#include <string.h>
# define ALL_SYMBOLS	"0123456789diuscpnfgexX%lh-+.*# "

typedef struct	q_list
{
	int			minus;
	int			wide;
	int 		precision;
	int			size;
}				p_list;
void 	ft_putchar(char c);
#endif //DESAUSAG_FT_PRINTF_H
