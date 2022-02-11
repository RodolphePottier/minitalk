/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atouli_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goldenboby <goldenboby@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 09:49:07 by rpottier          #+#    #+#             */
/*   Updated: 2022/01/02 21:14:22 by goldenboby       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	is_white_space(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

static ULI	ft_strlen_atoui(char *str)
{
	ULI	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static ULI	check_base(char *base)
{
	ULI	i;
	ULI	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || is_white_space(base[i]))
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

static ULI	ft_base_place(char *c, char *base)
{
	ULI	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == *c)
		{
			return (i);
		}
		i++;
	}
	return (150000);
}

ULI	ft_atouli_base(char *str, char *base)
{
	unsigned long int	nbr;
	int					i;

	i = 0;
	nbr = 0;
	if (!check_base(base))
		return (0);
	while (is_white_space(str[i]))
		i++;
	while (str[i] == '+')
		i++;
	while (ft_base_place(&str[i], base) != 150000)
	{
		nbr = (nbr * ft_strlen_atoui(base) + ft_base_place(&str[i], base));
		i++;
	}
	return (nbr);
}
