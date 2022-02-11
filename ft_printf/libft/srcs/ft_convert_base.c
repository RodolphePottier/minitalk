/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goldenboby <goldenboby@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:14:32 by goldenboby        #+#    #+#             */
/*   Updated: 2022/01/02 21:13:20 by goldenboby       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>
#include <stdio.h>

int				base_is_ok(char *base);
int				ft_base_place(char c, char *base);
char			put_nb(int nb, char *base);

static ULI	ft_strlen_atoui(char *str)
{
	ULI	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	nbr;
	int	sign;

	nbr = 0;
	sign = 1;
	i = 0;
	if (!base_is_ok(base))
		return (0);
	while (str[i] != '\0' && is_white_space(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while ((ft_base_place(str[i], base) >= 0))
	{
		nbr = (nbr * ft_strlen_atoui(base)) + (ft_base_place(str[i], base));
		i++;
	}
	return (nbr * sign);
}

int	int_size(ULI nb, int base_size)
{
	int	size;

	size = 0;
	if (nb == 0)
		size++;
	while (nb != 0)
	{
		nb = nb / base_size;
		size++;
	}
	return (size);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		tab_size;
	ULI		nb_from;
	char	*nb_to;

	if (!base_is_ok(base_from) || !base_is_ok(base_to))
		return (NULL);
	nb_from = ft_atoui_base(nbr, base_from);
	tab_size = int_size(nb_from, ft_strlen_atoui(base_to));
	nb_to = malloc(sizeof(char) * (tab_size + 1));
	nb_to[tab_size--] = '\0';
	while (nb_from >= ft_strlen_atoui(base_to) && (tab_size > 0))
	{
		nb_to[tab_size--] = put_nb(nb_from % ft_strlen_atoui(base_to), base_to);
		nb_from = nb_from / ft_strlen_atoui(base_to);
	}
	nb_to[tab_size] = put_nb((nb_from % ft_strlen_atoui(base_to)), base_to);
	return (nb_to);
}
