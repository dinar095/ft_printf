/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desausag <desausag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:15:50 by desausag          #+#    #+#             */
/*   Updated: 2021/01/23 22:01:34 by desausag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include "./libft/libft.h"
# define ALL_SYMBOLS	"0123456789diuscpxX%-+.*"

int				ft_printf(const char *format, ...);

int				start_function(char *str, va_list ap);

typedef struct	s_list
{
	int		flag;
	int		minus;
	int		wide;
	int		precision;
}				t_list;

void			parser(char **str, va_list ap, t_list *list);

int				processor(char **str, t_list *list, va_list ap);

int				int_function(t_list *strct, int x);

int				str_function(t_list *strct, char *x);

int				c_function(t_list *strct, char x);

int				ptr_function(t_list *strct, long unsigned int x);

int				wide_proc(int wide, char **d, char sym, int reverse);

int				ft_putchar(char c);

int				ft_putnbr(int n);

int				ft_putstr(char *s);

void			*ft_strset(void *destination, int c, size_t n);

int				uint_function(t_list *strct, unsigned int x);

int				qx_function(t_list *strct, unsigned int x, int flag);

int				p_wide(t_list *strct, char **tmp);

#endif
