/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:09:05 by lamici            #+#    #+#             */
/*   Updated: 2023/01/17 09:09:11 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_char(int c);
int		ft_digit(int n);
int		ft_hexd(unsigned int n, char format);
int		ft_path(unsigned long int n);
int		ft_printf(const char *str, ...);
int		ft_string(char *str);
int		ft_unsigned(unsigned int n);
int		ft_matrix(char **mat);

#endif
