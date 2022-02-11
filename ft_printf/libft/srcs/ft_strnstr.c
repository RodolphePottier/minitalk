/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:54:30 by rpottier          #+#    #+#             */
/*   Updated: 2021/11/26 15:57:40 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;
	char	*occur;

	occur = (char *) big;
	i = 0;
	if (!little[0])
		return (occur);
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (((big[i + j] == little[j]) && (i + j) < len) && big[i + j])
				j++;
			if (i + j > len)
				return (NULL);
			if (!little[j])
				return (&occur[i]);
		}
		i++;
	}
	return (NULL);
}
