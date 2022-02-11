/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr_length.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goldenboby <goldenboby@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 10:18:47 by goldenboby        #+#    #+#             */
/*   Updated: 2022/01/03 19:12:16 by goldenboby       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

unsigned int	get_arg_length(t_info *info, void *arg)
{
	if (info->convertion == 's')
	{
		if (!arg && info->precision && info->precision_size >= 6)
			return (ft_strlen("(null)"));
		else if (!arg && info->precision && info->precision_size > 0)
			return (0);
		else if (!arg && !info->precision)
			return (ft_strlen("(null)"));
		return (ft_strlen((char *)arg));
	}
	else if (info->convertion == 'c' || info->convertion == '%')
		return (1);
	else if (info->convertion == 'd' || info->convertion == 'i')
		return (ft_nbrlen_int(info, *(int *)arg));
	else if (ft_strrchr("xXu", info->convertion))
		return (ft_nbrlen_unsigned_int(info, (char *)arg));
	else if (info->convertion == 'p')
		return (ft_strlen((char *)arg));
	return (0);
}

unsigned int	ft_nbrlen_int(t_info *info, int nbr)
{
	unsigned int	nbrlen;
	unsigned int	nb;

	nbrlen = 0;
	if (nbr < 0)
		nb = -nbr;
	else
		nb = nbr;
	if (nb == 0 && info->precision && !(info->precision_size > 0))
		return (0);
	else if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		nbrlen++;
	}
	return (nbrlen);
}

size_t	ft_nbrlen_unsigned_int(t_info *info, char *nbr)
{
	if (nbr[0] == '0' && info->precision && info->precision_size == 0)
		return (0);
	else if (nbr[0] == 0)
		return (1);
	return (ft_strlen(nbr));
}

unsigned int	ui_nbrlen_base(unsigned int nbr, unsigned int base_length)
{
	unsigned int	length;

	length = 0;
	if (nbr == 0)
		length = 1;
	else
	{
		while (nbr > 0)
		{
			nbr = nbr / base_length;
			length++;
		}
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
