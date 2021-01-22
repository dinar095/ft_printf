/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desausag <desausag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 20:58:58 by desausag          #+#    #+#             */
/*   Updated: 2021/01/22 21:08:41 by desausag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
static char		ft_hex(int n)
{
	if (n == 10)
		return ('A');
	else if (n == 11)
		return ('B');
	else if (n == 12)
		return ('C');
	else if (n == 13)
		return ('D');
	else if (n == 14)
		return ('E');
	else if (n == 15)
		return ('F');
	else
		return (n + '0');
}

static size_t	count_len(unsigned long int n)
{
	if (n < 16)
		return (1);
	return (count_len(n / 16) + 1);
}

char	*ft_hex_big_itoa(unsigned long long n)
{
	int		i;
	char	*z;

	i = count_len(n);
	z = (char *)malloc(sizeof(char) * (i + 1));
	if (!z)
		return (NULL);
	z[i--] = '\0';
	z[0] = '0';
	while (n)
	{
		z[i] = ft_hex(n % 16);
		n = n / 16;
		i--;
	}
	return (z);
}
