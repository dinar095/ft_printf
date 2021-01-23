/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfiles.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desausag <desausag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 21:48:52 by desausag          #+#    #+#             */
/*   Updated: 2021/01/23 21:49:04 by desausag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		i += ft_putchar(*s++);
	}
	return (i);
}

int		ft_putnbr(int n)
{
	int		i;
	int		count;

	count = 0;
	i = n % 10 < 0 ? -1 : 1;
	if (n / 10)
		count += ft_putnbr(n / 10);
	else if (n < 0)
		count += ft_putchar('-');
	count += ft_putchar((n % 10) * i + '0');
	return (count);
}

void	*ft_strset(void *destination, int c, size_t n)
{
	unsigned char	*b;
	size_t			i;

	i = 0;
	b = (unsigned char *)destination;
	while (i != n)
	{
		b[i++] = c;
	}
	b[i] = '\0';
	return (destination);
}
