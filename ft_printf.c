/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:33:38 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/06 13:07:41 by jiwahn           ###   ########.fr       */
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

	init_buf(&buf);
	while (*fmt)
	{
		if (*fmt != '%')
		{
			buf = append_char_to_buf(buf, *fmt++);
			continue ;
		}
		++fmt;
		info.flag = check_flag(&fmt);
		info.width = check_width(&fmt);
		info.precision = check_precision(&fmt);
		buf = check_conversion(buf, info, &fmt, args);
		fmt++;
	}
	return (buf);
}

int	ft_printf(const char *fmt, ...)
{
	t_str	buf;
	va_list	args;

	va_start(args, fmt);
	buf = ft_vsprintf(fmt, args);
	va_end(args);
	if (write(STDOUT_FILENO, buf.str, buf.len) < 0)
		buf.len = -1;
	free(buf.str);
	return (buf.len);
}
