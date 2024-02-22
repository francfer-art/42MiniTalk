/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:11:14 by francfer          #+#    #+#             */
/*   Updated: 2023/11/28 08:58:57 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_long(char *base, unsigned long long n, int i)
{
	unsigned long long	len;

	len = ft_strlen(base);
	if (n >= len)
	{
		i = hex_long(base, n / len, i);
		ft_putchar_fd(base[n % len], 1);
		i++;
	}
	else if (n < len)
	{
		ft_putchar_fd(base[n], 1);
		i++;
	}
	return (i);
}

int	print_hex_lower(unsigned int n)
{
	int	total;

	total = 0;
	total = hex_long("0123456789abcdef", n, total);
	return (total);
}

int	print_hex_upper(unsigned int n)
{
	int	total;

	total = 0;
	total = hex_long("0123456789ABCDEF", n, total);
	return (total);
}

int	print_pointer(void *ptr)
{
	unsigned long long	address;
	int					total;

	address = (unsigned long long)ptr;
	total = 1;
	print_str("0x");
	total += hex_long("0123456789abcdef", address, total);
	return (total);
}

/*
int	main(void)
{
	unsigned long	value;
	
	value = 3454534;
	print_pointer(value, 87);
	return (0);
}
*/
