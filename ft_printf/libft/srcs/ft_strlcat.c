/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:53:56 by rpottier          #+#    #+#             */
/*   Updated: 2021/11/25 15:24:51 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#define SIZE_DST 6 

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_length;
	size_t	src_length;
	size_t	i;
	size_t	tmp;

	dst_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	i = 0;
	tmp = dst_length;
	if (size <= dst_length)
		return (size + src_length);
	while (src[i] != '\0' && tmp < size - 1)
	{
		dst[tmp] = src[i];
		i++;
		tmp++;
	}
	dst[tmp] = '\0';
	return (dst_length + src_length);
}
