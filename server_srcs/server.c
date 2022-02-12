/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:09:20 by rpottier          #+#    #+#             */
/*   Updated: 2022/02/12 00:52:14 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

t_server g_server;

// on passe par cette fonction à chaque réception de signal.

void	handle_sigusr(int sig, siginfo_t *sa, void *context)
{
	if (sig == SIGINT)
	{
		ft_printf(YEL "\nClosing server... Done.\n" RESET);
		if (g_server.str)
			free(g_server.str);
		exit(EXIT_SUCCESS);
	}
	int save_pid;
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

void	check_realloc(void)
{
	if (g_server.sig_count % (ALLOC_SIZE * 8) == 0 || g_server.sig_count == 1)
		alloc_str();
}

int check_bug_client(void)
{
	if (g_server.bug_client == 1)
	{
		ft_printf("An error has occured with the client, transmission failed\n");
		return (1);
	}
	return (0);
}

int char_is_receipted(void)
{
	if ((g_server.sig_count % 8) == 0 && g_server.sig_count != 0)
		return (1);
	return (0);
}

int full_transmission_succeed(void)
{
	if ((g_server.sig_count % 8) == 0 && g_server.str[g_server.index] == '\0')
		return (1);
	return (0);
}

void print_and_reset(void)
{
	if (kill(g_server.client_pid, SIGUSR2) == -1)
	{
		g_server.bug_client = 1;
		ft_printf("Not enable to send success confirmation to client\n");
	}
	else
	{
		ft_printf(GRN "Message from client n°" RESET RED "%d" RESET GRN " :\n" RESET, g_server.client_pid);
		ft_printf("%s\n", g_server.str);
	}
	reset_param();
}

void send_delivering_receipt(void)
{
	if (kill(g_server.client_pid, SIGUSR1) == -1)
		g_server.bug_client = 1;
}



void reset_for_new_client(void)
{
	reset_param();
	g_server.sig_count = 1;						// on remet à un car on a reçu un bit d'un nouveau processus
	alloc_str();
}

int main(void)
{
	start_server();
	while (KEEP_GOING)
	{
		while (!g_server.ready)
			usleep(500);
		check_realloc();									 // if str need more memory
		if (check_bug_client())
			reset_for_new_client();
		convert_binary_to_char();
		
		if (full_transmission_succeed())						// si on a reçu toute la chaine, on affiche
			print_and_reset();
		if (char_is_receipted())							// si on a recu les 8 bits du char, on incremente l'index
			g_server.index++;
		g_server.ready = 0;				// on remet la variable ready à 0 pour éviter de repasser dans les fonctions avant la reception d'un nouveau signal
		send_delivering_receipt();
	}
	return (0);
}
