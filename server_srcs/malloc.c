/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:12:13 by rpottier          #+#    #+#             */
/*   Updated: 2022/02/12 20:27:08 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void	get_message_len(int *len, int bit, int sig_count)
{
	int	i;

	i = (sizeof(int) * 8);
	if (bit == 1)
	{
		if ((sig_count % i) != 0)
			*len = *len | (1 << (i - (sig_count % i)));
		else
			*len = *len | 1;
	}
}

int	message_len_is_set(int sig_count, int size_of_int)
{
	if (sig_count > size_of_int)
		return (1);
	return (0);
}

void	malloc_str(t_buffer *buf)
{
	buf->str = ft_calloc(buf->len + 1, sizeof(char));
	if (!buf->str)
	{
		ft_printf(RED "Allocation failed\n" RESET);
		exit(EXIT_FAILURE);
	}
}
