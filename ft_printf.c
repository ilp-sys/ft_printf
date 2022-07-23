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

static void	init_buf(t_str *buf)
{
	buf->len = 0;
	buf->str = (char *)malloc(sizeof(char) * BUFSIZE);
}

t_str	ft_vsprintf(const char *fmt, va_list args)
{
	t_str	buf;
	t_info	info;

	while (*fmt)
	{
		if (*fmt != '%')
		{
			buf.str[buf.len++] = *fmt++;
			continue ;
		}
		++fmt;
		info.flag = check_flag(&fmt);
		info.width = check_width(&fmt);
		info.precision = check_precision(&fmt);
		buf = check_conversion(buf, info, &fmt, args);
		fmt++;
	}
	buf.str[buf.len] = '\0';
	return (buf);
}

int	ft_printf(const char *fmt, ...)
{
	t_str	buf;
	va_list	args;

	init_buf(&buf);
	va_start(args, fmt);
	buf = ft_vsprintf(buf, fmt, args);
	va_end(args);
	write(1, buf.str, buf.len);
	free(buf.str);
	return (buf.len);
}
