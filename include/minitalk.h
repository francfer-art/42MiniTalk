/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:15:33 by mulken            #+#    #+#             */
/*   Updated: 2024/02/21 11:04:50 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include "../Printf/ft_printf.h"

int		ft_atoi(char *str);
void	writing_signal(int x);
void	handler(int x);
void	sending_signal(int pid, char *str);

#endif
