/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:15:33 by lamici            #+#    #+#             */
/*   Updated: 2022/10/10 15:46:43 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (src[y] != '\0')
	{
		y++;
	}
	if (size != 0)
	{
		while (src[x] != '\0' && x < (size -1))
		{
			dest[x] = src[x];
			x++;
		}
		dest[x] = '\0';
	}
	return (y);
}
