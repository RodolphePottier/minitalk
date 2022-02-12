/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_reset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 00:51:14 by rpottier          #+#    #+#             */
/*   Updated: 2022/02/12 00:59:00 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

int	full_transmission_succeed(void)
{
	if ((g_server.sig_count % 8) == 0 && g_server.str[g_server.index] == '\0')
		return (1);
	return (0);
}

void	reset_param(void)
{
	if (g_server.str)
		free(g_server.str);
	set_param();
}

void	print_and_reset(void)
{
	if (kill(g_server.client_pid, SIGUSR2) == -1)
	{
		g_server.bug_client = 1;
		ft_printf("Not enable to send success confirmation to client\n");
	}
	else
	{
		ft_printf(GRN "Message from client n°" RESET RED "%d"
			RESET GRN " :\n" RESET, g_server.client_pid);
		ft_printf("%s\n", g_server.str);
	}
	reset_param();
}
