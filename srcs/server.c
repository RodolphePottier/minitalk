/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:09:20 by rpottier          #+#    #+#             */
/*   Updated: 2022/02/11 19:49:55 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

t_server g_server;

// on passe par cette fonction à chaque réception de signal.

void	handle_sigusr(int sig, siginfo_t *sa, void *context)
{
//	if (sig == SIGINT)
//	{
//		free(g_server.str);
//		exit(EXIT_SUCCESS);
//	}
	int save_pid;
	if (sig == SIGUSR1)
		g_server.bit_received = 0;
	else if (sig == SIGUSR2)
		g_server.bit_received = 1;
	
	save_pid = g_server.client_pid;
	g_server.client_pid = sa->si_pid;
	if (g_server.sig_count != 0 && save_pid != g_server.client_pid)
	{
		g_server.bug_client = 1;
	}
	g_server.sig_count++;
	g_server.ready = 1;
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

/*
** Initialisation de la struct sigaction
** Si SA_SIGINFO est indiqué dans sa_flags, alors sa_sigaction (plutôt que
** sa_handler) pointe vers le gestionnaire de signal pour signum.
** On modifie le traitement des signaux SIGUSR1 et SIGUSR2 pour toute la durée du programme.
** Affichage du pid du serveur.
*/

void start_server()
{
	struct sigaction sa;
	ft_memset(&sa, 0, sizeof(struct sigaction));
	set_param();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
//	sigaction(SIGINT, &sa, NULL);
}

void set_param(void)
{
	g_server.sig_count = 0;
	g_server.index = 0;
	g_server.ready = 0;
	g_server.str = NULL;
	g_server.bug_client = 0;
//	g_server.str = ft_calloc(ALLOC_SIZE + 1, sizeof(char));
//	if (!g_server.str)
//		exit(EXIT_FAILURE);
	g_server.size_alloc = 0;
	g_server.server_pid = getpid();
	ft_printf(YEL "Server pid: %d\n" RESET, g_server.server_pid);
}
 
void alloc_str(void)
{
	g_server.size_alloc++;
	g_server.str = ft_realloc(g_server.str, (ALLOC_SIZE * g_server.size_alloc) + 1);
	if (!g_server.str)
		exit(EXIT_FAILURE);
}

void reset_param(void)
{
	if (g_server.str)
		free(g_server.str);
	set_param();
}

int	str_need_more_memory(void)
{
	if (g_server.sig_count % (ALLOC_SIZE * 8) == 0 || g_server.sig_count == 1)
		return (1);
	return (0);
}

int bug_client()
{
	if (kill(g_server.client_pid, SIGUSR1) == -1 || g_server.bug_client)
		return (1);
	return (0);
}

int char_is_receipted(void)
{
	if ((g_server.sig_count % 8) == 0 && g_server.sig_count != 0)
		return (1);
	return (0);
}

int str_is_fully_recepteid(void)
{
	if ((g_server.sig_count % 8) == 0 && g_server.str[g_server.index] == '\0')
		return (1);
	return (0);
}

int main(void)
{
	start_server();
	while (1)
	{
		while (!g_server.ready)
			usleep(500);
		if (g_server.sig_count % (ALLOC_SIZE * 8) == 0 || g_server.sig_count == 1)
			alloc_str();									 // if str need more memory
			
		if (g_server.bug_client == 1)
		{
			reset_param();
			g_server.sig_count = 1;						// on remet à un car on a reçu un bit d'un nouveau processus
			alloc_str();
		}
		convert_binary_to_char();
		if (str_is_fully_recepteid())						// si on a reçu toute la chaine, on affiche
		{
			if (kill(g_server.client_pid, SIGUSR2) == -1)
				g_server.bug_client = 1;
			ft_printf("%s\n", g_server.str);
			reset_param();
		}
		if (char_is_receipted())							// si on a recu les 8 bits du char, on incremente l'index
			g_server.index++;
		g_server.ready = 0;
		if (kill(g_server.client_pid, SIGUSR1) == -1)
			g_server.bug_client = 1;						// on remet la variable ready à 0 pour éviter de repasser dans les fonctions avant la reception d'un nouveau signal
	}
	return (0);
}
