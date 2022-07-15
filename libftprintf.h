/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:23:29 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/15 22:29:55 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

//for bit masking
# define ZEROPAD 1
# define SIGN    2
# define PLUS    4
# define SPACE   8
# define LEFT    16
# define SMALL   32
# define SPECIAL 64

# define BASE_DEC 10
# define BASE_HEX 16

typedef struct s_info
{
	int	flag;
	int	width;
	int	precision;
}				t_info;

//ft_printf_utils.c
int		left_adjust(int *width);
int		skip_atoi(const char ***s);

//ft_printf.c
int		ft_printf(const char *fmt, ...);
int		ft_vsprintf(const char *fmt, va_list args);

//fr_printf_conversion1.c & fr_printf_conversion2.c
int		conversion_c(t_info info, va_list *args);
int		conversion_s(t_info info, va_list *args);
int		conversion_percent(va_list *args);
int		conversion_p(t_info info, va_list *args);
int		conversion_int(t_info info, va_list *args);
int		conversion_x(t_info nfo, va_list *args);

//ft_printf_check.c
int		check_flag(const char **fmt);
int		check_width(const char **fmt);
int		check_precision(const char **fmt);
int		check_conversion(t_info info, const char *fmt, va_list args);

//ft_printf_print_numbers.c
int		print_numbers(long num, int base, t_info info);

#endif
