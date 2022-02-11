/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_buffers_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goldenboby <goldenboby@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 19:00:53 by goldenboby        #+#    #+#             */
/*   Updated: 2022/01/03 19:11:46 by goldenboby       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** ce qu'on veut avec calcul_precision(), c'est déterminé la valeur réelle
** de la precision pour pouvoir ajuster la largeur minimal de champs par
** la suite de manière générale
*/
void	calcul_precision_padding(t_info *info)
{
	if (!info->precision)
		return ;
	if (info->convertion == 's' && info->precision_size > info->arg_size)
		info->precision_padding = 0;
	else if (info->convertion == 's' && info->precision_size < info->arg_size)
		info->arg_size = info->precision_size;
	else if (info->precision_size > info->arg_size)
		info->precision_padding = info->precision_size - info->arg_size;
}

void	calcul_width_padding(t_info *info)
{
	if (!info->width)
		return ;
	info->width_padding = info->width;
	if (info->negative || info->plus)
		info->width_padding--;
	if (!info->negative && info->space)
		info->width_padding--;
	if (info->convertion == 'p' || info->hashtag)
		info->width_padding -= 2;
	info->width_padding -= (info->precision_padding + info->arg_size);
	if (info->convertion == '%')
		info->width_padding = 0;
}

void	*free_buffers(t_all_buff *all_buff)
{
	if (all_buff->main_allocated && all_buff->main)
		free(all_buff->main);
	if (all_buff->prefix_allocated && all_buff->prefix)
		free(all_buff->prefix);
	if (all_buff->suffix_allocated && all_buff->suffix)
		free(all_buff->suffix);
	free(all_buff);
	return (NULL);
}
