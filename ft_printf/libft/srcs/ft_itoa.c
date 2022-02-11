/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:56:09 by rpottier          #+#    #+#             */
/*   Updated: 2021/11/25 17:31:01 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_is_negative(int nb)
{
	if (nb < 0)
		return (1);
	return (0);
}

static int	ft_get_length(int n)
{
	int				is_neg;
	int				length;
	unsigned int	nb;

	is_neg = ft_is_negative(n);
	if (is_neg)
	{
		length = 1;
		nb = -n;
	}
	else
	{
		length = 0;
		nb = n;
	}
	if (n == 0)
		length = 1;
	while (nb > 0)
	{
		length++;
		nb = nb / 10;
	}
	return (length);
}

static int	set_up_neg_array(char *array, int n)
{
	array[0] = '-';
	return (-n);
}

char	*ft_itoa(int n)
{
	int				length;
	unsigned int	nb;
	char			*array;

	length = ft_get_length(n);
	array = malloc(sizeof(char) * (length + 1));
	if (!array)
		return (NULL);
	if (n == 0)
		array[0] = '0';
	array[length] = '\0';
	if (ft_is_negative(n))
		nb = set_up_neg_array(array, n);
	else
	{
		nb = n;
	}
	while (nb > 0)
	{
		array[length - 1] = (nb % 10) + '0';
		nb = nb / 10;
		length--;
	}
	return (array);
}
