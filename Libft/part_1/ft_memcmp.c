/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:53:38 by lamici            #+#    #+#             */
/*   Updated: 2022/10/10 15:39:56 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			x;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *) str1;
	s2 = (unsigned char *) str2;
	x = 0;
	while (x < n)
	{
		if (s1[x] > s2[x])
			return (1);
		if (s1[x] < s2[x])
			return (-1);
		x++;
	}
	return (0);
}
