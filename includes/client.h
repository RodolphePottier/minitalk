/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:38:18 by rpottier          #+#    #+#             */
/*   Updated: 2022/02/12 20:40:47 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

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

/* ------------------- Utils -------------------------*/

# define _GNU_SOURCE
# define CHAR_BIT 7

/* --------------- Structure definition -------------- */

typedef struct s_client
{
	int		delivery_receipt;
	int		pid;
	char	*str;
	int		ready;
	int		sig_count;
	int		str_len;
}	t_client;

/* ----- main.c. ----- */

void	handle_sigusr(int sig, siginfo_t *sa, void *context);
void	convert_char_to_binary(int pid, char c);
void	send_len_by_signal(int client_pid, int str_len);

/* ----- client_utils.c ----- */

void	start_client(void);
void	send_str_by_signal(int pid, char *str);
void	ft_exit(void);

#endif