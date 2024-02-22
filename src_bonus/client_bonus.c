/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:12:08 by mulken            #+#    #+#             */
/*   Updated: 2024/02/22 17:37:46 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	ft_atoi(char *str)
{
	int	i;
	int	s;
	int	res;

	i = 0;
	s = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57 && str[i])
	{
		res = (str[i] - 48) + (res * 10);
		i++;
	}
	return (res * s);
}

void	ft_send_signal(int pid, char *str)
{
	int				i;
	unsigned char	c;

	while (*str)
	{
		i = 7;
		c = *str++;
		while (i >= 0)
		{
			if ((c >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			i--;
		}
	}
}

static void	server_ok(int x)
{
	if (x == SIGUSR1)
	{
		ft_printf("Mensaje Recibido!");
		exit(0);
	}
	else
		exit(1);
}

int	main(int argc, char *argv[])
{
	int	pid;

	pid = ft_atoi(argv[1]);
	if (argc != 3)
	{
		ft_printf("Error: wrong number of arguments\n");
		return (0);
	}
	else if (pid <= 0)
	{
		ft_printf("Error: wrong PID!\n");
		return (0);
	}
	ft_send_signal(pid, argv[2]);
	signal(SIGUSR1, server_ok);
	pause();
}
