/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:33:44 by lamici            #+#    #+#             */
/*   Updated: 2022/10/21 10:53:26 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	prova(unsigned int n, char format)
{
	if (n >= 16)
	{
		prova(n / 16, format);
		prova(n % 16, format);
	}
	else if (n > 9)
	{
		if (format == 'x')
			n = n + 87;
		else
			n = n + 55;
		write(1, &n, 1);
	}
	else
	{
		n = n + 48;
		write(1, &n, 1);
	}
}

int	ft_hexd(unsigned int n, char format)
{
	unsigned int	x;
	int				y;

	y = 1;
	x = n;
	prova(n, format);
	while (x >= 16)
	{
		x = x / 16;
		y++;
	}
	return (y);
}
