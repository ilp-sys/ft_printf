/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:33:38 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/20 13:54:35 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_output(int printed, char *buf)
{
	write(1, buf, printed);
}

int	ft_vsprintf(char *buf, const char *fmt, va_list args)
{
	char	*str;
	t_info	info;

	str = buf;
	while (*fmt)
	{
		if (*fmt != '%')
		{
			*str++ = *fmt++;
			continue ;
		}
		++fmt;
		info.flag = check_flag(&fmt);
		info.width = check_width(&fmt);
		info.precision = check_precision(&fmt);
		str = check_conversion(str, info, &fmt, args);
		fmt++;
	}
	*str = '\0';
	return (str - buf);
}

int	ft_printf(const char *fmt, ...)
{
	char	buf[BUFSIZE];
	va_list	args;
	int		printed;

	va_start(args, fmt);
	printed = ft_vsprintf(buf, fmt, args);
	va_end(args);
	ft_printf_output(printed, buf);
	return (printed);
}
