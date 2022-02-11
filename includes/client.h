/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:38:18 by rpottier          #+#    #+#             */
/*   Updated: 2022/02/10 20:55:29 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
#define CLIENT_H

#define _GNU_SOURCE
#define CHAR_BIT 7

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "../ft_printf/includes/ft_printf.h"

typedef struct s_client
{
    int		delivery_receipt;
	int		pid;
	char	*str;
	int		ready;
	int		sig_count;
    int str_len;
}   t_client;

/* -------- client.c --------*/

void   convert_char_to_binary(int pid, char c);
void	send_str_by_signal(int pid, char *str);

/* ----- client_debug.c -----*/

void	print_char_to_binary(char c);

#endif