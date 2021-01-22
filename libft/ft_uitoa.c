/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desausag <desausag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 21:02:36 by desausag          #+#    #+#             */
/*   Updated: 2021/01/22 21:02:36 by desausag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_len(unsigned int n)
{
	if (n < 10)
		return (1);
	return (count_len(n / 10) + 1);
}
char	*ft_uitoa(unsigned int n)
{
	int		i;
	char	*z;
	int		minus;

	i = count_len(n);
	minus = 1;
	z = (char *)malloc(sizeof(char) * (i + 1));
	z[i--] = '\0';
	z[0] = '0';
	while (n)
	{
		z[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (z);
}