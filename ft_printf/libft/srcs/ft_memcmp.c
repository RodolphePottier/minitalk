/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:52:50 by rpottier          #+#    #+#             */
/*   Updated: 2021/11/26 14:46:27 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str_1;
	unsigned char	*str_2;

	if (n == 0)
		return (0);
	i = 0;
	str_1 = (unsigned char *) s1;
	str_2 = (unsigned char *) s2;
	while (i < n - 1 && str_1[i] == str_2[i])
		i++;
	return ((unsigned char) str_1[i] - (unsigned char) str_2[i]);
}
