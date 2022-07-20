/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:23:29 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/20 12:06:19 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "libft/libft.h"

# define ZEROPAD 1
# define SIGN    2
# define PLUS    4
# define SPACE   8
# define LEFT    16
# define SMALL   32
# define SPECIAL 64

# define BASE_DEC 10
# define BASE_HEX 16
# define BUFSIZE 1024

typedef struct s_info
{
	int	flag;
	int	width;
	int	precision;
}				t_info;

typedef struct	s_chars
{
	char	c;
	char	sign;
	char	locase;
}				t_chars;

//ft_printf_utils.c
int			skip_atoi(const char ***s);
char		*set_width(char *str, int len, char c, int *width);
int			do_div(long *n, long base);

//ft_printf.c
int			ft_printf(const char *fmt, ...);
int			ft_vsprintf(char *buf, const char *fmt, va_list args);

//ft_printf_check.c
int			check_flag(const char **fmt);
int			check_width(const char **fmt);
int			check_precision(const char **fmt);
char		*check_conversion(char *str, t_info info, \
		const char **fmt, va_list args);

//fr_printf_conversion1.c & fr_printf_conversion2.c
char		*conversion_c(char *str, t_info info, va_list args);
char		*conversion_s(char *str, t_info info, va_list args);
char		*conversion_percent(char *str);
char		*conversion_p(char *str, t_info info, va_list args);
char		*conversion_int(char *str, t_info info, va_list args);
char		*conversion_x(char *str, t_info info, va_list args);

//ft_printf_print_numbers.c
char		*print_numbers(char *str, long num, int base, t_info info);

//ft_printf_print_numbers_utils.c
void		print_numbers_set_flag(t_chars *chars, int base, t_info *info);
void		print_numbers_set_sign(t_chars *chars, long *num, t_info *info);
char		*print_numbers_get_digits(long num, int base, t_chars *chars);
char		*print_numbers_fill_str(char *str, char *tmp, \
		t_chars chars, t_info info);

#endif
