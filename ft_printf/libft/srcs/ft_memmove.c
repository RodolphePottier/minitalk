/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:50:57 by rpottier          #+#    #+#             */
/*   Updated: 2021/11/24 17:38:58 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static void	ft_strcpy_from_begin(char *d, const char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
}

static void	ft_strcpy_from_end(char *d, const char *s, size_t n)
{
	int	i;

	i = (int)n;
	while (i >= 0)
	{
		d[i] = s[i];
		i--;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	long		dest_addr;
	long		src_addr;
	char		*d;
	const char	*s;

	if (!dest && !src)
		return (NULL);
	dest_addr = (unsigned long)dest;
	src_addr = (unsigned long)src;
	d = dest;
	s = src;
	if (src_addr < dest_addr)
		ft_strcpy_from_end(d, s, n - 1);
	else
		ft_strcpy_from_begin(d, s, n);
	return (dest);
}
