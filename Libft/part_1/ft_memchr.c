/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:56:18 by lamici            #+#    #+#             */
/*   Updated: 2022/10/14 14:33:31 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char		*x;
	size_t		y;

	x = (char *) str;
	y = 0;
	while (y < n)
	{
		if ((unsigned char)x[y] == (unsigned char)c)
			return ((char *)str + y);
		y++;
	}
	return (0);
}
