/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:55:20 by lamici            #+#    #+#             */
/*   Updated: 2022/10/21 10:57:02 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	prova(unsigned long int n)
{
	if (n >= 16)
	{
		prova(n / 16);
		prova(n % 16);
	}
	else
	{
		if (n > 9)
			n = n + 87;
		else
			n = n + 48;
		write(1, &n, 1);
	}
}

int	ft_path(unsigned long int n)
{
	unsigned long int		x;
	int						y;

	y = 1;
	x = n;
	if (x == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	prova(n);
	while (x >= 16)
	{
		x = x / 16;
		y++;
	}
	return (y + 2);
}
