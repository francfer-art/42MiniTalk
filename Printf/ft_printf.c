/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:59:22 by francfer          #+#    #+#             */
/*   Updated: 2024/02/21 09:55:41 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	format(char c, va_list args)
{
	unsigned int	i;

	i = 0;
	if (c == 'c')
		i += print_char(va_arg(args, int));
	else if (c == 's')
		i += print_str(va_arg(args, char *));
	else if (c == 'p')
		i += print_pointer(va_arg(args, void *));
	else if (c == 'i' || c == 'd')
		i += print_integer(va_arg(args, int));
	else if (c == 'u')
		i += print_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		i += print_hex_lower(va_arg(args, unsigned int));
	else if (c == 'X')
		i += print_hex_upper(va_arg(args, unsigned int));
	else if (c == '%')
		i += print_char('%');
	return (i);
}

int	ft_printf(char const *input, ...)
{
	va_list			args;
	unsigned int	i;
	unsigned int	total;

	if (write(1, "", 0) == -1)
		return (-1);
	i = 0;
	total = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%')
		{
			i++;
			total += format(input[i], args);
		}
		else
			total += print_char(input[i]);
		i++;
	}
	va_end(args);
	return (total);
}
