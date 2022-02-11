/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goldenboby <goldenboby@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:52:34 by rpottier          #+#    #+#             */
/*   Updated: 2022/01/02 21:14:58 by goldenboby       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	if (src)
	{
		while (src[i])
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_strlen_join(const char *str)
{
	int	length;

	length = 0;
	if (str)
		while (str[length])
			length++;
	return (length);
}

char	*ft_strdup(const char *s)
{
	char	*dup;

	dup = NULL;
	if (s)
		dup = malloc(sizeof(char) * (ft_strlen_join(s) + 1));
	if (dup == NULL || !s)
		return (NULL);
	return (ft_strcpy(dup, s));
}
