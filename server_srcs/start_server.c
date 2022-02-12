/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 00:46:58 by rpottier          #+#    #+#             */
/*   Updated: 2022/02/12 00:48:00 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void start_server()
{
	struct sigaction sa;
	ft_memset(&sa, 0, sizeof(struct sigaction));
	set_param();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGINT, &sa, NULL);
}


void set_param(void)
{
	g_server.sig_count = 0;
	g_server.index = 0;
	g_server.ready = 0;
	g_server.str = NULL;
	g_server.bug_client = 0;
	g_server.size_alloc = 0;
	g_server.server_pid = getpid();
	ft_printf(YEL "Server n°" RESET RED "%d" RESET YEL " waiting for client...\n" RESET, g_server.server_pid);
}

void	check_realloc(void)
{
	if (g_server.sig_count % (ALLOC_SIZE * 8) == 0 || g_server.sig_count == 1)
		alloc_str();
}

void alloc_str(void)
{
	g_server.size_alloc++;
	g_server.str = ft_realloc(g_server.str, (ALLOC_SIZE * g_server.size_alloc) + 1);
	if (!g_server.str)
		exit(EXIT_FAILURE);
}