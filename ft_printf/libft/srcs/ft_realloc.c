/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goldenboby <goldenboby@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 10:00:45 by goldenboby        #+#    #+#             */
/*   Updated: 2022/01/02 21:14:47 by goldenboby       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_realloc(char *str, int size)
{
	char	*new_str;

	new_str = malloc(sizeof(*new_str) * size);
	if (new_str)
		ft_bzero(new_str, size);
	else
		return (NULL);
	if (str)
	{
		ft_strlcpy(new_str, str, size);
		free(str);
	}
	return (new_str);
}
