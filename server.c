/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:11:58 by mulken            #+#    #+#             */
/*   Updated: 2024/01/31 16:14:02 by francfer         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minitalk.h"

void	ft_bit_write(int x)
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

void	ft_signal_control(int x)
{
	if (x == SIGUSR1)
		ft_bit_write(1);
	else
		ft_bit_write(0);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Pid--> %u\n", pid);
	signal(SIGUSR1, ft_signal_control);
	signal(SIGUSR2, ft_signal_control);
	while (1)
	{
		pause();
	}
}
