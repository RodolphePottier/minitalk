/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:38:18 by rpottier          #+#    #+#             */
/*   Updated: 2022/02/12 02:36:22 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
#define SERVER_H

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define RESET "\x1B[0m"

#define _GNU_SOURCE
#define ALLOC_SIZE 50
#define FT_STDOUT 1
#define KEEP_GOING 1
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

typedef struct s_buffer
{
	char	*str;
	int		index;
}   t_buffer;


/*----- start_server.c -----*/

void	start_server(void);
void	set_param(void);
void	check_realloc(void);
void	alloc_str(void);

/*----- reception.c -----*/

void	handle_sigusr(int sig, siginfo_t *sa, void *context);
void	convert_binary_to_char(void);
int		char_is_receipted(void);
void	send_delivering_receipt(void);

/*----- bug_client.c -----*/

int		check_bug_client(void);
void	reset_for_new_client(void);

/*----- print_and_reset.c -----*/

int		full_transmission_succeed(void);
void	reset_param(void);
void	print_and_reset(void);

#endif