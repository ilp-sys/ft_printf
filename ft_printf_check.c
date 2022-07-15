/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:44:10 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/15 22:45:08 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	check_flag(const char **fmt)
{
	int	flag;

	flag = 0;
	while (**fmt)
	{
		if (**fmt == '-')
			flag |= LEFT;
		else if (**fmt == '+')
			flag |= PLUS;
		else if (**fmt == ' ')
			flag |= SPACE;
		else if (**fmt == '#')
			flag |= SPECIAL;
		else if (**fmt == '0')
			flag |= ZEROPAD;
		else
			break ;
		(*fmt)++;
	}
	return (flag);
}

int	check_width(const char **fmt)
{
	int	width;

	width = -1;
	if (ft_isdigit(**fmt))
		width = skip_atoi(&fmt);
	return (width);
}

int	check_precision(const char **fmt)
{
	int	precision;

	precision = -1;
	if (**fmt == '.')
	{
		++(*fmt);
		if (ft_isdigit(**fmt))
			precision = skip_atoi(&fmt);
		if (precision < 0)
			precision = 0;
	}
	return (precision);
}

int	check_conversion(t_info info, const char **fmt, va_list args)
{
	int	printed;

	if (**fmt == 'c')
		printed += conversion_c(info, &args);
	else if (**fmt == 's')
		printed += conversion_s(info, &args);
	else if (**fmt == 'p')
		printed += conversion_p(info, &args);
	else if (**fmt == 'd' || **fmt == 'i' || **fmt == 'u')
	{
		if (**fmt == 'd' || **fmt == 'i')
			flag |= SIGN;
		printed += conversion_int(info, &args);
	}
	else if (**fmt == 'x' || **fmt == 'X')
	{
		if (**fmt == 'x')
			flag |= SMALL;
		printed += conversion_x(info, &args);
	}
	else if (**fmt == '%')
		printed += conversion_percent(&args);
	return (printed);
}
