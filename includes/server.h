/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:38:18 by rpottier          #+#    #+#             */
/*   Updated: 2022/02/11 16:25:58 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
#define SERVER_H

#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"

#define _GNU_SOURCE
#define ALLOC_SIZE 50
#define FT_STDOUT 1
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "../ft_printf/includes/ft_printf.h"

typedef struct s_server
{
	int		bit_received;
	int		client_pid;
	int		server_pid;
	char	*str;
	int		size_alloc;
	int		index;
	int		ready;
	int		sig_count;
	int		bug_client;
}   t_server;

/* -------- server.c --------*/


void	handle_sigusr(int sig, siginfo_t *sa, void *context);
void	convert_binary_to_char(void);
void	start_server();
void	set_param(void);

#endif