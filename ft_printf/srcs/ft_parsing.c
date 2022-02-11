/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goldenboby <goldenboby@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:05:54 by rpottier          #+#    #+#             */
/*   Updated: 2022/01/03 19:12:21 by goldenboby       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*parse_str(char *str, t_info *info, va_list ap)
{
	str = find_flag(str + 1, info);
	str = find_width(str, ap, info);
	str = find_precision(str, ap, info);
	str = find_convertion(str, info);
	return (str);
}

/*
** Cette fonction s'occupe de determiner quels flag sont present
** Elle retourne l'addresse du caractere suivant le dernier flag
*/

char	*find_flag(char *str, t_info *info)
{
	int	i;

	i = 0;
	while (str[i] && ft_strchr(FLAG, str[i]))
	{
		if (!info->precision && str[i] == '0')
			info->zero = TRUE;
		else if (str[i] == '-')
		{
			info->zero = FALSE;
			info->minus = TRUE;
		}
		else if (str[i] == '#')
			info->hashtag = TRUE;
		else if (str[i] == '+')
			info->plus = TRUE;
		else if (str[i] == ' ')
			info->space = TRUE;
		if (info->plus)
			info->space = FALSE;
		info->flag_presence = TRUE;
		i++;
	}
	return (&str[i]);
}

/*
** Si on a une largeur de champ, on va rempli notre struct info
** avec la longueur indiquee a l aide de atoi qui s arretera au
** premier non digit rencontrer
*/
char	*find_width(char *str, va_list ap, t_info *info)
{
	int	i;

	i = 0;
	if (str[i] && ft_isdigit(str[i]))
	{
		info->width = ft_atoi(&str[i]);
		while (str[i] && ft_isdigit(str[i]))
			i++;
	}
	else if (str[i] && str[i] == '*')
	{
		info->width = va_arg(ap, int);
		if (info->width < 0)
		{
			info->width = info->width * -(1);
			info->zero = FALSE;
			info->minus = TRUE;
		}
		i++;
	}
	return (&str[i]);
}

/*
** Cette fonction determine la precision a applique
** 
*/
char	*find_precision(char *str, va_list ap, t_info *info)
{
	int	i;

	i = 0;
	if (!(str[i] == '.'))
		return (&str[i]);
	info->precision = TRUE;
	i++;
	if (str[i] && ft_isdigit(str[i]))
	{
		info->precision_size = ft_atoi(&str[i]);
		while (str[i] && ft_isdigit(str[i]))
			i++;
	}
	else if (str[i] && str[i] == '*')
	{
		info->precision_size = va_arg(ap, int);
		if (info->precision_size < 0)
		{
			info->precision_size = 0;
			info->precision = FALSE;
		}
		i++;
	}
	info->zero = FALSE;
	return (&str[i]);
}

char	*find_convertion(char *str, t_info *info)
{
	if (ft_strchr(CONVERTION, *str))
		info->convertion = *str;
	if (info->convertion == 'i')
		info->convertion = 'd';
	if (info->convertion == 's')
	{
		info->zero = FALSE;
		info->plus = FALSE;
		info->space = FALSE;
	}
	return (str + 1);
}
