/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goldenboby <goldenboby@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 09:34:33 by rpottier          #+#    #+#             */
/*   Updated: 2022/01/02 18:37:51 by goldenboby       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int	ui_nbrlen_base(unsigned int nbr, unsigned int base_length)
{
	unsigned int	length;

	length = 0;
	while (nbr > 0)
	{
		nbr = nbr / base_length;
		length++;
	}
	return (length);
}

unsigned int	check_base(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < ' ' || base[i] > '~')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i > 1)
		return (i);
	return (0);
}

unsigned int	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	base_length;
	unsigned int	nb;
	unsigned int	nbr_length;

	nbr_length = 0;
	base_length = check_base(base);
	if (base_length)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nb = -nbr;
			nbr_length = 1;
		}
		else
			nb = nbr;
		nbr_length += ui_nbrlen_base(nb, base_length);
		if (nb >= base_length)
		{
			ft_putnbr_base(nb / base_length, base);
			nb = nb % base_length;
		}
		ft_putchar(base[nb]);
	}
	return (nbr_length);
}
