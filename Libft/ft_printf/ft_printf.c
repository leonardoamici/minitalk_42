/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:21:06 by lamici            #+#    #+#             */
/*   Updated: 2022/10/21 09:34:03 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_conv(va_list ap, char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len = ft_char(va_arg(ap, int));
	if (format == 's')
		print_len = ft_string(va_arg(ap, char *));
	if (format == 'p')
		print_len = ft_path(va_arg(ap, unsigned long));
	if (format == 'd' || format == 'i')
		print_len = ft_digit(va_arg(ap, int));
	if (format == 'u')
		print_len = ft_unsigned(va_arg(ap, unsigned int));
	if (format == 'x' || format == 'X')
		print_len = ft_hexd(va_arg(ap, unsigned int), format);
	if (format == 'M')
		print_len = ft_matrix(va_arg(ap, char **));
	if (format == '%')
	{
		write(1, "%", 1);
		print_len = 1;
	}
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		print_len;
	va_list	ap;

	i = 0;
	print_len = 0;
	va_start(ap, str);
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			print_len += ft_conv(ap, str[i + 1]);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			print_len += 1;
		}
		i++;
	}
	va_end(ap);
	return (print_len);
}
