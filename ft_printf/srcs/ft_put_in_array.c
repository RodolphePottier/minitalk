/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_in_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goldenboby <goldenboby@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 10:24:41 by goldenboby        #+#    #+#             */
/*   Updated: 2022/01/03 19:12:31 by goldenboby       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	putchar_in_array(char *buff, char c)
{
	int	index;

	index = ft_strlen(buff);
	buff[index] = c;
	index++;
	return (1);
}

int	putnstr_in_array(t_info *info, char *buff, char *str)
{
	int	index;

	index = 0;
	index = ft_strlen(buff);
	if (str && info->convertion == 's' && info->precision)
		ft_strlcpy(&buff[index], str, info->precision_size + 1);
	else if (str)
		ft_strlcpy(&buff[index], str, ft_strlen(str) + 1);
	return (ft_strlen(buff));
}

int	put_0x_in_array(t_info *info, char *prefix, void *arg)
{
	if (*(char *)arg != '0')
	{
		if (info->convertion == 'x' || info->convertion == 'p')
		{
			putchar_in_array(prefix, '0');
			putchar_in_array(prefix, 'x');
			return (2);
		}
		else if (info->convertion == 'X')
			return (putnstr_in_array(info, prefix, "0X"));
	}
	return (0);
}

UI	putnbr_array_int(t_all_buff *all_buff, char *base, int nbr)
{
	unsigned int	base_length;
	unsigned int	nb;
	unsigned int	nbr_length;

	nbr_length = 0;
	base_length = check_base(base);
	if (base_length)
	{
		if (nbr < 0)
			nb = -nbr;
		else
			nb = nbr;
		nbr_length += ui_nbrlen_base(nb, base_length);
		if (nb >= base_length)
		{
			putnbr_array_int(all_buff, base, nb / base_length);
			nb = nb % base_length;
		}
		all_buff->main[all_buff->main_index] = (base[nb]);
		all_buff->main_index++;
	}
	return (nbr_length);
}
