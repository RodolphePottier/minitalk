/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_debug.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:18:08 by rpottier          #+#    #+#             */
/*   Updated: 2022/02/08 16:18:29 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

void	print_char_to_binary(char c)
{
	int		i;

	i = CHAR_BIT;
	while (i >= 0)
	{
		if ((c & (1 << i)) > 0)
			printf("1 ");
		else
			printf("0 ");
		i--;
	}
	printf("\n");
}