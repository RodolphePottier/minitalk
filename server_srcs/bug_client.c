/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bug_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 00:49:59 by rpottier          #+#    #+#             */
/*   Updated: 2022/02/12 00:57:48 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

int	check_bug_client(void)
{
	if (g_server.bug_client == 1)
	{
		ft_printf("An error has occured with the client, transmission failed\n");
		return (1);
	}
	return (0);
}

/*
** on remet à un car on a reçu un bit d'un nouveau processus
*/

void	reset_for_new_client(void)
{
	reset_param();
	g_server.sig_count = 1;
	alloc_str();
}
