/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:43:35 by lamici            #+#    #+#             */
/*   Updated: 2022/10/14 12:17:09 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_chessboxing(int n)
{
	long	j;
	long	nb;

	nb = n;
	j = 0;
	if (nb > 0)
	{
		while (nb >= 1)
		{
			nb /= 10;
			j++;
		}
	}
	else
	{
		j = 1;
		while (nb < 0)
		{
			nb /= 10;
			j++;
		}
	}
	return (j);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	y;
	long	z;

	if (n < 0)
	{
		y = n;
		y = -y;
	}
	else
		y = n;
	z = ft_chessboxing(n);
	str = malloc(sizeof(char) * (z + 1));
	str[z--] = '\0';
	while (z >= 0)
	{
		str[z] = (y % 10) + 48;
		y /= 10;
		z--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
