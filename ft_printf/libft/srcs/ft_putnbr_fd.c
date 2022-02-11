/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:55:42 by rpottier          #+#    #+#             */
/*   Updated: 2021/11/23 13:55:43 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static unsigned int	return_nbr_length(unsigned int nbr)
{
	unsigned int	length;

	length = 0;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		length++;
	}
	return (length);
}

unsigned int	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;
	unsigned int	nbr_length;

	nbr_length = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -n;
		nbr_length = 1;
	}
	else
		nbr = n;
	nbr_length += return_nbr_length(nbr);
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		nbr = nbr % 10;
	}
	if (nbr < 10)
		ft_putchar_fd(nbr + '0', fd);
	return (nbr_length);
}
