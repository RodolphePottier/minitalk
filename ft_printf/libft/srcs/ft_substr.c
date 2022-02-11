/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:52:15 by rpottier          #+#    #+#             */
/*   Updated: 2021/11/30 11:43:36 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			len_from_start;
	char			*str;

	len_from_start = 0;
	if (!s)
		return (NULL);
	i = start;
	if (start < (unsigned int)ft_strlen(s))
		len_from_start = ft_strlen(&s[start]);
	if (len_from_start < len)
	{
		str = malloc(sizeof(char) * (len_from_start + 1));
		len = len_from_start;
	}
	else
		str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (start < (unsigned int)ft_strlen(s))
		while (s[start] && i < (unsigned int) len)
			str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
