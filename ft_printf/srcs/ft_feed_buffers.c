/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_feed_buffers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goldenboby <goldenboby@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 10:25:13 by goldenboby        #+#    #+#             */
/*   Updated: 2022/01/03 19:12:10 by goldenboby       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	feed_buffer(t_all_buff *all_buff, t_info *info, void *arg)
{
	if (all_buff->prefix)
		feed_prefix(info, all_buff->prefix, arg);
	if (all_buff->main)
		feed_main(arg, info, all_buff);
	if (all_buff->suffix)
		feed_suffix(info, all_buff->suffix);
}

void	feed_prefix(t_info *info, char *prefix, void *arg)
{
	if (info->width_padding > 0 && !info->minus && !info->zero)
		info->count += put_space_in_array(info->width_padding, prefix);
	if (info->negative)
		info->count += putchar_in_array(prefix, '-');
	if (!info->negative && info->plus)
		info->count += putchar_in_array(prefix, '+');
	if (!info->negative && info->space)
		info->count += putchar_in_array(prefix, ' ');
	if (info->hashtag || info->convertion == 'p')
		info->count += put_0x_in_array(info, prefix, arg);
	if (info->precision_padding > 0)
		info->count += put_zero_in_array(info->precision_padding, prefix);
	if (info->zero && info->width_padding && !info->precision)
		info->count += put_zero_in_array(info->width_padding, prefix);
}

void	feed_main(void *arg, t_info *info, t_all_buff *all_buff)
{
	if (info->precision && info->precision_size == 0 && info->arg_size == 0)
		return ;
	if (info->convertion == 'c' || info->convertion == '%')
		info->count += putchar_in_array(all_buff->main, *(char *)arg);
	if (info->convertion == 'd' || info->convertion == 'i')
		info->count += putnbr_array_int(all_buff, DECIMAL, *(int *)arg);
	if (ft_strchr("sxXup", info->convertion))
		info->count += putnstr_in_array(info, all_buff->main, (char *)arg);
}

void	feed_suffix(t_info *info, char *suffix)
{
	if (suffix && info->minus && info->width && !info->zero)
		info->count += put_space_in_array(info->width_padding, suffix);
}
