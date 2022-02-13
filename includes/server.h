/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:38:18 by rpottier          #+#    #+#             */
/*   Updated: 2022/02/13 18:29:07 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# define _GNU_SOURCE
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../ft_printf/includes/ft_printf.h"

/* ------------------- Colors -------------------------*/

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define RESET "\x1B[0m"

# define SUCCESS 1
# define FAILURE 0

/* --------------- Structure definition -------------- */

typedef struct s_server
{
	int		bit;
	int		client_pid;
	int		ready;
	int		count;
}	t_server;

typedef struct s_buffer
{
	char	*str;
	int		index;
	int		len;
}	t_buffer;

/* ------------------- Prototypes ---------------------- */

/*----- mains_server.c -----*/

void	handle_sigusr(int sig, siginfo_t *sa, void *context);
void	set_sigaction(void);
int		send_delivering_receipt(void);

/*----- malloc.c -----*/

void	get_message_len(int *len, int bit, int sig_count);
int		message_len_is_set(int sig_count, int size_of_int);
void	malloc_str(t_buffer *buf);

/*----- Transmission_and_reset.c -----*/

void	binary_to_char(char *buffer, int *index, int bit, int sig_count);
int		full_transmission_succeed(int sig_count, int size_of_int, int len);
void	reset(t_buffer *message, t_server *server);
void	print_and_reset(t_buffer *message, t_server *server, int status);

#endif