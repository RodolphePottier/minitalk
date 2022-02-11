/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 09:49:07 by rpottier          #+#    #+#             */
/*   Updated: 2021/08/11 17:37:15 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_white_space(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	check_base(char *base)
{
	unsigned int	i;
	unsigned int	j;

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

int	ft_base_place(char *c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == *c)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nbr;
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	nbr = 0;
	if (!check_base(base))
		return (0);
	while (is_white_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while ((ft_base_place(&str[i], base)) >= 0)
	{
		nbr = (nbr * ft_strlen(base) + ft_base_place(&str[i], base));
		i++;
	}
	return (nbr * sign);
}
