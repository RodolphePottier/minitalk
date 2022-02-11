/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goldenboby <goldenboby@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:36:11 by rpottier          #+#    #+#             */
/*   Updated: 2022/01/03 19:10:52 by goldenboby       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define DECIMAL "0123456789"
# define HEXA_UP "0123456789ABCDEF"
# define HEXA_LOW "0123456789abcdef"
# define FT_STDOUT 1
# define ULI unsigned long int
# define UI unsigned int
# define CONVERTION "cspdiuxX%"
# define FLAG "-0#+ "
# define TRUE 1
# define FALSE 0
# define BOOL unsigned int

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# include "../libft/includes/libft.h"

typedef struct s_str_info
{
	BOOL			hashtag;
	BOOL			plus;
	BOOL			space;
	BOOL			zero;
	BOOL			minus;
	BOOL			precision;
	BOOL			negative;
	BOOL			flag_presence;
	int				arg_size;
	int				width_padding;
	int				width;
	int				precision_padding;
	int				precision_size;
	int				convertion;
	int				count;
}	t_info;

typedef struct s_all_buffer
{
	char	*prefix;
	char	*main;
	char	*suffix;
	BOOL	prefix_allocated;
	BOOL	main_allocated;
	BOOL	suffix_allocated;
	BOOL	main_index;
}	t_all_buff;

typedef struct s_arg
{
	BOOL	need_to_free;
	int		arg_int;
	char	*arg_str;
	void	*arg_address;
}	t_arg;

/* ft_printf.c */
int			ft_printf(const char *format, ...);
int			apply_convertion(va_list ap, t_info *info);
void		display_buffer(t_info *info, t_all_buff *all_buffer);
void		flush_info(t_info *info);

/* ft_arg_utils.c */
void		*get_arg(t_arg *arg, va_list ap, t_info *info);
char		*check_arg_and_precision_null(t_info *info, char *str);
char		*convert_decimal_base(t_info *info, ULI arg);
void		flush_arg(t_arg *arg);
int			free_arg(t_arg *arg);

/* ft_parsing.c */
char		*parse_str(char *str, t_info *info, va_list ap);
char		*find_flag(char *str, t_info *info);
char		*find_width(char *str, va_list ap, t_info *info);
char		*find_precision(char *str, va_list ap, t_info *info);
char		*find_convertion(char *str, t_info *info);

/* ft_alloc_buffers.c */

t_all_buff	*alloc_all_buffer(t_info *info, t_all_buff *all_buff);
char		*alloc_main_buff(t_info *info, t_all_buff *all_buff);
char		*alloc_prefix_buff(t_info *info, t_all_buff *all_buff);
char		*alloc_suffix_buff(t_info *info, t_all_buff *all_buff);
void		flush_buff_struc(t_all_buff *all_buff);

/* ft_feed_buffers */

void		feed_buffer(t_all_buff *all_buf, t_info *info, void *arg);
void		feed_prefix(t_info *info, char *prefix, void *arg);
void		feed_main(void *arg, t_info *info, t_all_buff *all_buff);
void		feed_suffix(t_info *info, char *suffix);

/* ft_feed_buffer_utils.c */

UI			put_space_in_array(int n, char *buff);
UI			put_zero_in_array(int n, char *buff);

/* ft_alloc_buffers_utils.c */

void		calcul_precision_padding(t_info *info);
void		calcul_width_padding(t_info *info);
void		*free_buffers(t_all_buff *all_buff);

/* ft_put_in_array.c */
int			putchar_in_array(char *buff, char c);
int			putnstr_in_array(t_info *info, char *buff, char *str);
int			put_0x_in_array(t_info *info, char *prefix, void *arg);
UI			putnbr_array_int(t_all_buff *all_buff, char *base, int nbr);

/* ft_get_nbr_length.c */

UI			get_arg_length(t_info *info, void *arg);
UI			ft_nbrlen_int(t_info *info, int nbr);
size_t		ft_nbrlen_unsigned_int(t_info *info, char *nbr);
UI			ui_nbrlen_base(unsigned int nbr, unsigned int base_length);
UI			check_base(char *base);

#endif