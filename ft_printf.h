/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desausag <desausag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 12:15:50 by desausag          #+#    #+#             */
/*   Updated: 2021/01/22 21:29:45 by desausag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DESAUSAG_FT_PRINTF_H
# define DESAUSAG_FT_PRINTF_H

#include <stdarg.h>
#include <string.h>
# define ALL_SYMBOLS	"0123456789diuscpxX%-+.*"

typedef struct	q_list
{
	int 		flag;
	int			minus;
	int			wide;
	int 		precision;
}				p_list;
int 	ft_printf(const char *format, ...);
int		start_function(char *str, va_list ap);
void	parser(char **str, va_list ap, p_list *list);
void	reset_list(p_list **list);
void 	precision(char **str, p_list **list, va_list ap);
void 	wide(char **str, p_list **list, va_list ap);
void	flags(char **str, p_list **list);
int		processor(char **str, p_list *list, va_list ap);
int		int_function(p_list **list, int x);
int		str_function(p_list **list, char *x);
int		c_function(p_list **list, char x);
int		ptr_function(p_list **list, unsigned long long x);
char	*ft_itoa_uhex(unsigned long long n);
int		wide_proc(int wide, char **d, char sym, int reverse);
int 	ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
void	*ft_strset(void *destination, int c, size_t n);
char	*ft_uitoa(unsigned int n);
int 	x_function(p_list **list, unsigned long long x);
int 	bx_function(p_list **list, unsigned long long x);


#endif //DESAUSAG_FT_PRINTF_H
