/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goldenboby <goldenboby@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 10:21:56 by goldenboby        #+#    #+#             */
/*   Updated: 2022/01/03 19:12:00 by goldenboby       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	*get_arg(t_arg *arg, va_list ap, t_info *info)
{
	if (ft_strchr("cid%", info->convertion))
	{
		if (info->convertion == '%')
			arg->arg_int = '%';
		else
			arg->arg_int = va_arg(ap, int);
		if (info->convertion != 'c' && arg->arg_int < 0)
			info->negative = TRUE;
		return (&arg->arg_int);
	}
	arg->need_to_free = TRUE;
	if (info->convertion == 's')
		arg->arg_str = ft_strdup(va_arg(ap, char *));
	else
		arg->arg_str = convert_decimal_base(info, va_arg(ap, ULI));
	arg->arg_str = check_arg_and_precision_null(info, arg->arg_str);
	if (arg->arg_str)
		return (arg->arg_str);
	return (NULL);
}

char	*check_arg_and_precision_null(t_info *info, char *str)
{
	if (info->convertion == 'p' && str[0] == '0')
	{
		free(str);
		str = ft_strdup("0x0");
	}
	if (ft_strchr("xX", info->convertion)
		&& info->hashtag && str[0] == '0')
		info->hashtag = FALSE;
	if (!str && info->convertion == 's' && (!info->precision
			|| (info->precision && info->precision_size >= 6)))
		str = ft_strdup("(null)");
	return (str);
}

char	*convert_decimal_base(t_info *info, ULI arg)
{
	char	*arg_decimal;
	char	*arg_hexadecimal;

	if (info->convertion == 'p')
		arg_decimal = ft_ulitoa(arg);
	else
		arg_decimal = ft_ulitoa((UI)arg);
	if (!arg_decimal)
		return (NULL);
	if (info->convertion == 'x' || info->convertion == 'p')
		arg_hexadecimal = ft_convert_base(arg_decimal, DECIMAL, HEXA_LOW);
	if (info->convertion == 'X')
		arg_hexadecimal = ft_convert_base(arg_decimal, DECIMAL, HEXA_UP);
	if (info->convertion == 'u')
		return (arg_decimal);
	if (!arg_hexadecimal)
		return (NULL);
	free(arg_decimal);
	return (arg_hexadecimal);
}

void	flush_arg(t_arg *arg)
{
	arg->need_to_free = FALSE;
	arg->arg_int = 0;
	arg->arg_str = NULL;
	arg->arg_address = NULL;
}

int	free_arg(t_arg *arg)
{
	if (arg && arg->arg_address && arg->need_to_free)
		free(arg->arg_address);
	free(arg);
	return (0);
}
