/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 00:48:19 by rpottier          #+#    #+#             */
/*   Updated: 2022/02/12 01:04:53 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void	handle_sigusr(int sig, siginfo_t *sa, void *context)
{
	int	save_pid;

	if (sig == SIGINT)
	{
		ft_printf(YEL "\nClosing server... Done.\n" RESET);
		if (g_server.str)
			free(g_server.str);
		exit(EXIT_SUCCESS);
	}
	if (sig == SIGUSR1)
		g_server.bit_received = 0;
	else if (sig == SIGUSR2)
		g_server.bit_received = 1;
	save_pid = g_server.client_pid;
	g_server.client_pid = sa->si_pid;
	if (g_server.sig_count != 0 && save_pid != g_server.client_pid)
		g_server.bug_client = 1;
	g_server.sig_count++;
	g_server.ready = 1;
}

void	convert_binary_to_char(void)
{
	if (g_server.bit_received == 1)
	{
		if ((g_server.sig_count % 8) != 0)
			g_server.str[g_server.index] |= 1 << 8 - g_server.sig_count % 8;
		else
			g_server.str[g_server.index] |= 1;
	}
}

void	convert_binary_to_char(void)
{
	if (g_server.bit_received == 1)
	{
		if ((g_server.sig_count % 8) != 0)
			g_server.str[g_server.index] |= (1 << (8 - (g_server.sig_count % 8)));
		else
			g_server.str[g_server.index] |= 1;
	}
}

int char_is_receipted(void)
{
	if ((g_server.sig_count % 8) == 0 && g_server.sig_count != 0)
		return (1);
	return (0);
}
