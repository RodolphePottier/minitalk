/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goldenboby <goldenboby@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:56:54 by rpottier          #+#    #+#             */
/*   Updated: 2021/12/30 00:02:10 by goldenboby       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

void	*ft_calloc(size_t nmenb, size_t size)
{
	void	*array;

	array = malloc(size * nmenb);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, size * nmenb);
	return (array);
}
