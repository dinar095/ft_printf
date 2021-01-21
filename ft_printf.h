/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desausag <desausag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:15:50 by desausag          #+#    #+#             */
/*   Updated: 2021/01/21 09:32:39 by desausag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DESAUSAG_FT_PRINTF_H
# define DESAUSAG_FT_PRINTF_H

#include <stdarg.h>
#include <string.h>
# define ALL_SYMBOLS	"0123456789diuscpnfgexX%lh-+.*# "

typedef struct	q_list
{
	int 		flag;
	int			minus;
	int			wide;
	int 		precision;
	int			size;
}				p_list;
void 	ft_putchar(char c);
void	ft_putnbr(int n);
void	int_function(p_list *list, int x);
void	str_function(p_list *list, char *x);
void	processor(char **str, p_list *list, va_list ap);
void	flags(char **str, p_list *list);
void 	wide(char **str, p_list *list, va_list ap);
void 	precision(char **str, p_list *list, va_list ap);
void 	reset_list(p_list *list);
p_list	*parser(char **str, va_list ap);
void	start_function(char *str, va_list ap);
int 	ft_printf(const char *format, ...);
void	ft_putstr(char *s);
void	*ft_strset(void *destination, int c, size_t n);
#endif //DESAUSAG_FT_PRINTF_H
