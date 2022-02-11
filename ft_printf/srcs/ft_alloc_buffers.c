/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_buffers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goldenboby <goldenboby@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 10:24:12 by goldenboby        #+#    #+#             */
/*   Updated: 2022/01/03 19:11:54 by goldenboby       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_all_buff	*alloc_all_buffer(t_info *info, t_all_buff *all_buff)
{
	if (!all_buff)
		return (NULL);
	flush_buff_struc(all_buff);
	all_buff->main = alloc_main_buff(info, all_buff);
	if (!all_buff->main && all_buff->main_allocated)
		return (NULL);
	all_buff->prefix = alloc_prefix_buff(info, all_buff);
	if (!all_buff->prefix && all_buff->prefix_allocated)
		return (free_buffers(all_buff));
	all_buff->suffix = alloc_suffix_buff(info, all_buff);
	if (!all_buff->suffix && all_buff->suffix_allocated)
		return (free_buffers(all_buff));
	return (all_buff);
}

void	flush_buff_struc(t_all_buff *all_buff)
{
	all_buff->main = NULL;
	all_buff->prefix = NULL;
	all_buff->suffix = NULL;
	all_buff->main_allocated = FALSE;
	all_buff->prefix_allocated = FALSE;
	all_buff->suffix_allocated = FALSE;
	all_buff->main_index = 0;
}

char	*alloc_main_buff(t_info *info, t_all_buff *all_buff)
{
	if (info->convertion == 's' && info->precision
		&& info->precision_size < info->arg_size)
		all_buff->main = ft_calloc(info->precision_size + 1, sizeof(char));
	else
		all_buff->main = ft_calloc(info->arg_size + 1, sizeof(char));
	all_buff->main_allocated = TRUE;
	if (!all_buff->main)
		return (NULL);
	return (all_buff->main);
}

char	*alloc_prefix_buff(t_info *info, t_all_buff *all_buff)
{
	int	size;

	size = 0;
	if (info->negative || info->plus)
		size++;
	if (info->space)
		size++;
	if (info->convertion == 'p'
		|| (ft_strchr("xX", info->convertion) && info->hashtag))
		size = size + 2;
	if (info->precision_padding > 0)
		size = size + info->precision_padding;
	if (!info->minus && info->width_padding > 0)
		size = size + info->width_padding;
	if (size > 0)
	{
		all_buff->prefix = ft_calloc(size + 1, sizeof(char));
		all_buff->prefix_allocated = TRUE;
	}
	if (!all_buff->prefix)
		return (NULL);
	return (all_buff->prefix);
}

char	*alloc_suffix_buff(t_info *info, t_all_buff *all_buff)
{
	if (!info->minus)
		return (NULL);
	if (info->width_padding > 0)
	{
		all_buff->suffix = ft_calloc(info->width_padding + 1, sizeof(char));
		all_buff->suffix_allocated = TRUE;
	}
	if (!all_buff->suffix)
		return (NULL);
	return (all_buff->suffix);
}
