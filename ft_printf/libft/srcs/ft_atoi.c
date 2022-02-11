/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:57:00 by rpottier          #+#    #+#             */
/*   Updated: 2021/11/24 17:39:29 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

static int	is_negative(char c)
{
	if (c == '-')
		return (1);
	return (0);
}

static int	is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	nb;

	sign = 1;
	i = 0;
	nb = 0;
	while (is_white_space(nptr[i]))
		i++;
	if (is_sign(nptr[i]))
	{
		if (is_negative(nptr[i]))
			sign = -sign;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		nb = (nb * 10) + (nptr[i] - '0');
		i++;
	}
	return (nb * sign);
}
