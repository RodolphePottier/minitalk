/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:34:14 by rpottier          #+#    #+#             */
/*   Updated: 2022/02/13 20:22:40 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/client.h"

static t_client	g_client;

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf(RED "Wrong number of agument\n" RESET);
		return (1);
	}
	start_client();
	g_client.pid = ft_atoi(argv[1]);
	if (g_client.pid <= 0)
	{
		ft_printf(RED "Transmission failed. The server pid is negative or equal to 0\n" RESET);
		return (1);
	}
	g_client.str = argv[2];
	g_client.str_len = ft_strlen(argv[2]);
	if (g_client.str_len == 0)
	{
		ft_printf(YEL "Empty string. Nothing to send.\n" RESET);
		return (1);
	}
	send_len_by_signal(g_client.pid, g_client.str_len);
	send_str_by_signal(g_client.pid, g_client.str);
	ft_printf(GRN "Transimission succeed\n");
	return (0);
}

void	handle_sigusr(int sig, siginfo_t *sa, void *context)
{
	(void) sa;
	(void) context;
	if (sig == SIGUSR1)
		g_client.delivery_receipt = 1;
	if (sig == SIGUSR2)
		g_client.delivery_receipt = 2;
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
		while (!g_client.delivery_receipt)
			;
		g_client.delivery_receipt = 0;
		i--;
	}
}

void	send_len_by_signal(int client_pid, int str_len)
{
	int	i;

	i = (sizeof(int) * 8) - 1;
	while (i >= 0)
	{
		if ((str_len & (1 << i)) > 0)
		{
			if (kill(client_pid, SIGUSR2) == -1)
				ft_exit();
		}
		else
		{
			if (kill(client_pid, SIGUSR1) == -1)
				ft_exit();
		}
		while (!g_client.delivery_receipt)
			;
		g_client.delivery_receipt = 0;
		i--;
	}
}
