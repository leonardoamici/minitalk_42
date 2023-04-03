/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:06:27 by lamici            #+#    #+#             */
/*   Updated: 2022/10/14 12:17:53 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1l;
	int		s2l;
	char	*dest;

	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	dest = malloc(sizeof(char) * (s1l + s2l + 1));
	ft_strlcpy(dest, s1, s1l + 1);
	ft_strlcat(dest, s2, s1l + s2l + 1);
	return (dest);
}
