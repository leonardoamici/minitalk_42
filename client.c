/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:05:57 by lamici            #+#    #+#             */
/*   Updated: 2024/01/19 17:07:16 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>
#include "Libft/libft.h"
#include <unistd.h>

int		g_check = 0;

static void	ft_conv(char c, int pid)
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

static void	ft_pidconv(char c, int pid, char *my_pid)
{
	int	x;
	int check;

	x = 0;
	while (x < 8)
	{
		if ((c % 2) == 0)
			check = kill(pid, SIGUSR1);
		else
			check = kill(pid, SIGUSR2);
		if (check == -1 && my_pid)
		{
			free(my_pid);
			exit(1);
		}
		c = c >> 1;
		x++;
		usleep(200);
	}
}

static void	ft_msgover(int signal)
{
	g_check = 0;
	if (signal == SIGUSR2)
		exit (0);
}

int	main(int ac, char **av)
{
	int		i;
	int		s;
	char	*pid;

	i = 0;
	s = 0;
	signal(SIGUSR2, ft_msgover);
	signal(SIGUSR1, ft_msgover);
	if (ac == 3 && av[2][0] && ft_atoi(av[1]) > 0)
	{
		pid = ft_itoa(getpid());
		while (pid[i] != '\0')
		{
			ft_pidconv(pid[i], ft_atoi(av[1]), pid);
			i++;
		}
		free(pid);
		ft_pidconv('\0', ft_atoi(av[1]), NULL);
		while (av[2][s] != '\0')
			ft_conv(av[2][s++], ft_atoi(av[1]));
		ft_conv('\n', ft_atoi(av[1]));
		ft_conv('\0', ft_atoi(av[1]));
	}
	return (0);
}
