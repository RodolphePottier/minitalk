/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goldenboby <goldenboby@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:39:42 by rpottier          #+#    #+#             */
/*   Updated: 2022/01/03 19:12:26 by goldenboby       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_info	info;
	char	*str;

	va_start(ap, format);
	str = (char *)format;
	info.count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			flush_info(&info);
			str = parse_str(str, &info, ap);
			if (!apply_convertion(ap, &info))
				return (-1);
		}
		else
			info.count += ft_putchar_fd(*str++, FT_STDOUT);
	}
	va_end(ap);
	return (info.count);
}

int	apply_convertion(va_list ap, t_info *info)
{
	t_all_buff		*all_buff;
	t_arg			*arg;

	all_buff = ft_calloc(1, sizeof(t_all_buff));
	if (!all_buff)
		return (0);
	arg = ft_calloc(1, sizeof(t_arg));
	if (!arg)
	{
		free(all_buff);
		return (0);
	}
	flush_arg(arg);
	arg->arg_address = get_arg(arg, ap, info);
	info->arg_size = get_arg_length(info, arg->arg_address);
	calcul_precision_padding(info);
	calcul_width_padding(info);
	if (!alloc_all_buffer(info, all_buff))
		return (free_arg(arg));
	feed_buffer(all_buff, info, arg->arg_address);
	display_buffer(info, all_buff);
	free_buffers(all_buff);
	free_arg(arg);
	return (1);
}

void	flush_info(t_info *info)
{
	info->hashtag = FALSE;
	info->plus = FALSE;
	info->space = FALSE;
	info->zero = FALSE;
	info->minus = FALSE;
	info->negative = FALSE;
	info->precision = FALSE;
	info->flag_presence = FALSE;
	info->arg_size = 0;
	info->width_padding = 0;
	info->precision_padding = 0;
	info->width = 0;
	info->precision_size = 0;
	info->convertion = 0;
}

void	display_buffer(t_info *info, t_all_buff *all_buffer)
{
	if (all_buffer->prefix && all_buffer->prefix[0] != '\0')
		ft_putstr_fd(all_buffer->prefix, FT_STDOUT);
	if (info->convertion == 'c' && all_buffer->main
		&& !ft_isprint(all_buffer->main[0]))
		ft_putchar_fd(all_buffer->main[0], FT_STDOUT);
	else if (all_buffer->main)
		ft_putstr_fd(all_buffer->main, FT_STDOUT);
	if (all_buffer->suffix)
		ft_putstr_fd(all_buffer->suffix, FT_STDOUT);
}
