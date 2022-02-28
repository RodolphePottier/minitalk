/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:37:02 by rpottier          #+#    #+#             */
/*   Updated: 2022/02/28 15:41:21 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/client.h"

/*
** Initialisation de la struct sigaction
** Si SA_SIGINFO est indiqué dans sa_flags, alors sa_sigaction (plutôt que
** sa_handler) pointe vers le gestionnaire de signal pour signum.
** On modifie le traitement des signaux SIGUSR1 et SIGUSR2 pour toute la durée
** du programme.
*/

void	start_client(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

void	ft_exit(void)
{
	ft_printf(RED "Transmission failed, please check server pid.\n" RESET);
	exit(EXIT_FAILURE);
}

void	send_str_by_signal(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		convert_char_to_binary(pid, str[i]);
		i++;
	}
	convert_char_to_binary(pid, '\0');
}
