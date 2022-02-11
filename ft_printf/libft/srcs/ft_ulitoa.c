/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goldenboby <goldenboby@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:56:09 by rpottier          #+#    #+#             */
/*   Updated: 2021/12/31 19:04:14 by goldenboby       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_get_length(unsigned long int n)
{
	int				length;

	length = 0;
	if (n == 0)
		length = 1;
	while (n > 0)
	{
		length++;
		n = n / 10;
	}
	return (length);
}

char	*ft_ulitoa(unsigned long int n)
{
	int				length;
	char			*array;

	length = ft_get_length(n);
	array = malloc(sizeof(char) * (length + 1));
	if (!array)
		return (NULL);
	if (n == 0)
		array[0] = '0';
	array[length] = '\0';
	while (n > 0)
	{
		array[length - 1] = (n % 10) + '0';
		n = n / 10;
		length--;
	}
	return (array);
}
