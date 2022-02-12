/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transmission_and_reset.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:12:46 by rpottier          #+#    #+#             */
/*   Updated: 2022/02/12 20:32:13 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void	binary_to_char(char *buffer, int *index, int bit, int sig_count)
{
	int	relative_count;

	relative_count = sig_count - (sizeof(int) * 8);
	if (bit == 1)
	{
		if ((sig_count % 8) != 0)
			buffer[*index] |= (1 << (8 - (relative_count % 8)));
		else
			buffer[*index] |= 1;
	}
	if ((relative_count % 8) == 0 && relative_count != 0)
		*index = *index + 1;
}

int	full_transmission_succeed(int sig_count, int size_of_int, int len)
{
	if (sig_count == size_of_int + (len + 1) * 8)
		return (1);
	return (0);
}

void	reset(t_buffer *message, t_server *server)
{
	if (message->str)
		free(message->str);
	ft_memset(message, '\0', sizeof(t_buffer));
	ft_memset(server, '\0', sizeof(t_server));
}

void	print_and_reset(t_buffer *message, t_server *server, int status)
{
	ft_printf("-------------------------------------------\n\n");
	ft_printf(YEL "Client n°" RESET);
	ft_printf(RED "%d" RESET, server->client_pid);
	if (status == SUCCESS)
	{
		ft_printf(YEL" send a message:\n" RESET);
		ft_printf("%s\n\n", message->str);
	}
	else if (status == FAILURE)
		ft_printf(YEL" failed\n\n" RESET);
	reset(message, server);
}
