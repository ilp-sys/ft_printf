/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:23:29 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/20 13:38:37 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "libft/libft.h"

# define ZEROPAD 0x01
# define SIGN    0x02
# define PLUS    0x04
# define SPACE   0x08
# define LEFT    0x10
# define SMALL	 0x20 
# define SPECIAL 0x40 
# define NULLIFY 0x80

# define BASE_DEC 10
# define BASE_HEX 16
# define BUFSIZE 1024

typedef struct s_str
{
	int		len;
	char	*str;
}				t_str;

typedef struct s_info
{
	int	flag;
	int	width;
	int	precision;
}				t_info;

typedef struct s_chars
{
	char	c;
	char	sign;
	char	locase;
}				t_chars;

//ft_printf_utils.c
int			skip_atoi(const char ***s);
t_str		set_width(t_str buf, int len, char c, int *width);
int			do_div(long *n, long base);
void		check_buf(t_str *buf);
t_str		append_char_to_buf(t_str buf, char c);

//ft_printf.c
int			ft_printf(const char *fmt, ...);
t_str		ft_vsprintf(const char *fmt, va_list args);

//ft_printf_check.c
int			check_flag(const char **fmt);
int			check_width(const char **fmt);
int			check_precision(const char **fmt);
t_str		check_conversion(t_str buf, t_info info, \
		const char **fmt, va_list args);

//fr_printf_conversion1.c & fr_printf_conversion2.c
t_str		conversion_c(t_str buf, t_info info, va_list args);
t_str		conversion_s(t_str buf, t_info info, va_list args);
t_str		conversion_percent(t_str buf);
t_str		conversion_p(t_str buf, t_info info, va_list args);
t_str		conversion_int(t_str buf, t_info info, va_list args);
t_str		conversion_x(t_str buf, t_info info, va_list args);

//ft_printf_print_numbers.c
t_str		print_numbers(t_str buf, long num, int base, t_info info);

//ft_printf_print_numbers_utils.c
void		print_numbers_set_flag(t_chars *chars, int base, t_info *info);
void		print_numbers_set_sign(t_chars *chars, long *num, t_info *info);
char		*print_numbers_get_digits(long num, int base, \
		t_chars *chars, t_info info);
t_str		print_numbers_fill_str(t_str buf, char *tmp, \
		t_chars chars, t_info info);

#endif
