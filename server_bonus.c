/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:26:17 by lamici            #+#    #+#             */
/*   Updated: 2024/01/19 17:04:28 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>
#include "Libft/libft.h"
#include <unistd.h>

int		g_checker = 0;

static int	ft_power(int base, int power)
{
	int	res;
	int	i;

	if (power == 0)
		return (1);
	i = 1;
	res = base;
	while (i < power)
	{
		res *= base;
		i++;
	}
	return (res);
}

static void	ft_reconv(int signal, int *pid)
{
	static int	i;
	static int	x;
	static int	newpid;

	if (signal == SIGUSR2)
		x += ft_power(2, i);
	i++;
	if (*pid != 0)
		newpid = *pid;
	if (i == 8 && x != 0)
	{
		write(1, &x, 1);
		x = 0;
		i = 0;
		g_checker = 0;
	}
	else if (i == 8 && x == 0)
	{
		kill(newpid, SIGUSR2);
		write(1, "🦔message received!🦔\n", 26);
		*pid = 0;
		i = 0;
		g_checker = 0;
	}
	kill(newpid, SIGUSR1);
}

static int	ft_pidconv(int signal)
{
	static int	a;
	static int	b;
	static int	tpid;
	int			pid;

	pid = 0;
	if (signal == SIGUSR2)
		b += ft_power(2, a);
	a++;
	if (a == 8 && b != 0)
	{
		tpid = (tpid * 10) + b - '0';
		b = 0;
		a = 0;
	}
	else if (a == 8 && b == 0)
	{
		pid = tpid;
		tpid = 0;
		a = 0;
		g_checker = 1;
	}
	return (pid);
}

static void	ft_sortsig(int signal)
{
	static int	pid;

	if (g_checker == 0 && pid == 0)
		pid = ft_pidconv(signal);
	else
		ft_reconv(signal, &pid);
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, ft_sortsig);
	signal(SIGUSR2, ft_sortsig);
	while (1)
		pause();
}
