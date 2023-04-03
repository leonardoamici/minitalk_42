/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:05:57 by lamici            #+#    #+#             */
/*   Updated: 2023/01/30 09:05:59 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>
#include "Libft/libft.h"
#include <unistd.h>

int		g_check = 0;

void	ft_conv(char c, int pid)
{
	int	x;

	x = 0;
	while (x < 8)
	{
		while (g_check)
			usleep(10);
		g_check = 1;
		if ((c % 2) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1;
		x++;
	}
}

void	ft_pidconv(char c, int pid)
{
	int	x;

	x = 0;
	while (x < 8)
	{
		if ((c % 2) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1;
		x++;
		usleep(200);
	}
}

void	ft_msgover(int signal)
{
	g_check = 0;
	if (signal == SIGUSR2)
	{
		write(1, "message sent!\n", 14);
		exit (0);
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		s;
	char	*pid;

	i = 0;
	s = 0;
	pid = ft_itoa(getpid());
	signal(SIGUSR2, ft_msgover);
	signal(SIGUSR1, ft_msgover);
	if (ac == 3 && av[2][0] && ft_atoi(av[1]))
	{
		while (pid[i] != '\0')
		{
			ft_pidconv(pid[i], ft_atoi(av[1]));
			i++;
		}
		free(pid);
		ft_pidconv('\0', ft_atoi(av[1]));
		while (av[2][s] != '\0')
			ft_conv(av[2][s++], ft_atoi(av[1]));
		ft_conv('\n', ft_atoi(av[1]));
		ft_conv('\0', ft_atoi(av[1]));
	}
	usleep(100);
	return (0);
}
