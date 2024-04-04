/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:15:19 by francfer          #+#    #+#             */
/*   Updated: 2024/03/11 10:37:22 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	writing_signal(int x)
{
	static int	bit = 7;
	static int	set = 0;

	set += (x << bit);
	if (bit == 0)
	{
		ft_printf("%c", set);
		bit = 7;
		set = 0;
	}
	else
		bit--;
}

void	handler(int x)
{
	if (x == SIGUSR1)
		writing_signal(1);
	else
		writing_signal(0);
}

void	leaks()
{
	system("leaks server");
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Aloey! Im the Server %u\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	atexit(leaks);
}
