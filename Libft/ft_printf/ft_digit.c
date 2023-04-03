/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:47:24 by lamici            #+#    #+#             */
/*   Updated: 2022/10/21 10:33:21 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_stampa(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_stampa(n / 10);
		ft_stampa(n % 10);
	}
	else
	{
		n = n + 48;
		write(1, &n, 1);
	}
}

int	ft_digit(int n)
{
	long			x;
	int				y;

	y = 1;
	x = n;
	ft_stampa(n);
	if (x < 0)
	{
		y++;
		x = -x;
	}
	while (x >= 10)
	{
		x = x / 10;
		y++;
	}
	return (y);
}
