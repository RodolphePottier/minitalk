/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:23:01 by rpottier          #+#    #+#             */
/*   Updated: 2022/02/11 19:56:13 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/client.h"

//#include "../ft_printf/libft/includes/libft.h"

t_client g_client;

void ft_exit()
{
	ft_printf("Transmission failed, please check server pid.\n");
	exit(EXIT_FAILURE);
}

void	handle_sigusr(int sig, siginfo_t *sa, void *context)
{
	if (sig == SIGUSR1)
		g_client.delivery_receipt = 1;
	if (sig == SIGUSR2)
		ft_printf("Transmission succeed.\n");
}

void	convert_char_to_binary(int pid, char c)
{
	int		i;

	i = CHAR_BIT;
	while (i >= 0)
	{
		
		if ((c & (1 << i)) > 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_exit();
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_exit();
		}
		while (!g_client.delivery_receipt);
//		while (!g_client.delivery_receipt)
//		{
//			usleep(2000);
//			if (!g_client.delivery_receipt &&)
//				ft_printf("Server failed\n");
//		}
//		while (1);
		g_client.delivery_receipt = 0;
		i--;
	}
//	printf("\n");
//	sleep(1);
}

void	send_str_by_signal(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		convert_char_to_binary(pid, str[i]);
		i++;
	//	ft_putchar_fd('\n', 1);
	}
	convert_char_to_binary(pid, '\0');
}

void start_client()
{
	struct sigaction sa;
	ft_memset(&sa, 0, sizeof(struct sigaction));
	// Initialisation de la struct sigaction
	// Si SA_SIGINFO est indiqué dans sa_flags, alors sa_sigaction (plutôt que
    // sa_handler) pointe vers le gestionnaire de signal pour signum.
	
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_sigusr;

	// On modifie le traitement des signaux SIGUSR1 et SIGUSR2 pour toute la durée du programme.

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Wrong number of agument\n");
		return (1);
	}
	
	start_client();
	g_client.pid = ft_atoi(argv[1]);
	if (g_client.pid < 0)
	{
		ft_printf("Transmission failed. The server pid is negative\n");
		return (1);
	}
	g_client.str = argv[2];
	g_client.str_len = ft_strlen(argv[2]);
	send_str_by_signal(g_client.pid, g_client.str);
	return (0);
}