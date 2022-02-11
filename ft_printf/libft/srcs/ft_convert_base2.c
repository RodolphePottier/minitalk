/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goldenboby <goldenboby@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:46:17 by goldenboby        #+#    #+#             */
/*   Updated: 2022/01/02 21:15:22 by goldenboby       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	base_is_ok(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base || base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || base[i] <= ' ' || base[i] > '~')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_base_place(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

char	put_nb(unsigned int nb, char *base)
{
	return (base[nb]);
}

unsigned int	check_neg(int nb, char **nb_to)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		nbr = nb * -1;
		(*nb_to)[0] = '-';
		(*nb_to)[1] = '\0';
		return (nbr);
	}	
	else
	{
		nbr = nb;
		return (nbr);
	}
}
