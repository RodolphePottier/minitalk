/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_feed_buffers_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goldenboby <goldenboby@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 10:24:28 by goldenboby        #+#    #+#             */
/*   Updated: 2022/01/03 19:12:05 by goldenboby       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

unsigned int	put_space_in_array(int n, char *buff)
{
	int	i;
	int	index;

	index = ft_strlen(buff);
	i = 0;
	if (n <= 0)
		return (0);
	while ((int)i < n)
	{
		buff[index] = ' ';
		index++;
		i++;
	}
	return (n);
}

unsigned int	put_zero_in_array(int n, char *buff)
{
	unsigned int	i;
	int				index;

	index = ft_strlen(buff);
	i = 0;
	if (!buff || n <= 0)
		return (0);
	while ((int)i < n)
	{
		buff[index] = '0';
		index++;
		i++;
	}
	return (n);
}
