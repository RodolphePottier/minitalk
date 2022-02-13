/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:11:59 by rpottier          #+#    #+#             */
/*   Updated: 2022/02/13 19:13:28 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/server.h"

static t_server	g_server = {0};

int	main(void)
{
	t_buffer	buf;
	int			size_of_int;

	size_of_int = (sizeof(int) * 8);
	ft_memset(&buf, '\0', sizeof(t_buffer));
	set_sigaction();
	ft_printf(GRN"\nServer n°" RESET RED "%d" RESET, getpid());
	ft_printf(GRN " listening...\n\n" RESET);
	while (1)
	{
		while (!g_server.ready)
			usleep(400);
		g_server.ready = 0;
		if (g_server.count <= size_of_int)
			get_message_len(&buf.len, g_server.bit, g_server.count);
		if (!buf.str && message_len_is_set(g_server.count, size_of_int))
			malloc_str(&buf);
		if (buf.str)
			binary_to_char(buf.str, &buf.index, g_server.bit, g_server.count);
		if (!send_delivering_receipt())
			print_and_reset(&buf, &g_server, FAILURE);
		if (full_transmission_succeed(g_server.count, size_of_int, buf.len))
			print_and_reset(&buf, &g_server, SUCCESS);
	}
	return (0);
}

void	set_sigaction(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

// on passe par cette fonction à chaque réception de signal.

void	handle_sigusr(int sig, siginfo_t *sa, void *context)
{
	(void) context;
	g_server.client_pid = sa->si_pid;
	if (sig == SIGUSR1)
		g_server.bit = 0;
	else if (sig == SIGUSR2)
		g_server.bit = 1;
	g_server.count++;
	g_server.ready = 1;
}

int	send_delivering_receipt(void)
{
	if (kill(g_server.client_pid, SIGUSR1) == -1)
		return (0);
	return (1);
}
