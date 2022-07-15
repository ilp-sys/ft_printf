/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:33:38 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/15 22:26:19 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_vsprintf(const char *fmt, va_list args)
{
	int		printed;
	t_info	info;

	printed = 0;
	while (*fmt)
	{
		if (*fmt != '%')
		{
			ft_putchar(*fmt++);
			printed++;
			continue ;
		}
		info.flag = check_flag(&fmt);
		info.width = check_width(&fmt);
		info.precision = check_precision(&fmt);
		printed += check_conversion(info, &fmt, args);
		fmt++;
	}
	return (printed);
}

int	ft_printf(const char *fmt, ...)
{
	int		printed;
	va_list	args;

	va_start(args, fmt);
	printed = ft_vsprintf(fmt, args);
	va_end(args);
	return (printed);
}
