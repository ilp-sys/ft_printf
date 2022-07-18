/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:23:29 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/18 12:49:46 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
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

//ft_printf_utils.c
int			skip_atoi(const char ***s);
char		*set_width(char *str, int len, char c, int *width);
int			do_div(unsigned long *n, unsigned long base);

//ft_printf.c
int			ft_printf(const char *fmt, ...);
int			ft_vsprintf(char *buf, const char *fmt, va_list args);

//ft_printf_check.c
int			check_flag(const char **fmt);
int			check_width(const char **fmt);
int			check_precision(const char **fmt);
char		*check_conversion(char *str, t_info info, \
		const char *fmt, va_list args);

//fr_printf_conversion1.c & fr_printf_conversion2.c
char		*conversion_c(char *str, t_info info, va_list *args);
char		*conversion_s(char *str, t_info info, va_list *args);
char		*conversion_percent(char *str);
char		*conversion_p(char *str, t_info info, va_list *args);
char		*conversion_int(char *str, t_info info, va_list *args);
char		*conversion_x(char *str, t_info info, va_list *args);

//ft_printf_print_numbers.c
char		*print_numbers(char *str, long num, int base, t_info info);

//ft_printf_print_numbers_utils.c
static void	print_numbers_set_flag(char *c, char *locase, \
		int base, t_info *info);
static void	print_numbers_set_sign(char *sign, long num, t_info *info);
static char	*print_numbers_get_digits(long num, int base, int locase);
static char	*print_numbers_fill_str1(char *str, char *tmp, \
		char sign, t_info info);
static char	*print_numbers_fill_str2(char *str, char *tmp, char c, t_info info);

#endif
