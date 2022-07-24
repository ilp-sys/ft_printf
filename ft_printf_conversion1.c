/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:39:21 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/19 20:39:41 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str	conversion_c(t_str buf, t_info info, va_list args)
{
	if (!(info.flag & LEFT))
		while (--info.width > 0)
			buf = append_char_to_buf(buf, ' ');
	buf = append_char_to_buf(buf, va_arg(args, int));
	while (--info.width > 0)
		buf = append_char_to_buf(buf, ' ');
	return (buf);
}

t_str	conversion_s(t_str buf, t_info info, va_list args)
{
	int		i;
	int		len;
	char	*s;

	i = 0;
	s = va_arg(args, char *);
	if (s == NULL)
		s = "(null)";
	if (info.precision == -1)
		len = ft_strlen(s);
	else
		len = ft_strnlen(s, info.precision);
	if (!(info.flag & LEFT))
		while (len < info.width--)
			buf = append_char_to_buf(buf, ' ');
	while (i++ < len)
		buf = append_char_to_buf(buf, *s++);
	while (len < info.width--)
		buf = append_char_to_buf(buf, ' ');
	return (buf);
}

t_str	conversion_percent(t_str buf)
{
	buf = append_char_to_buf(buf, '%');
	return (buf);
}
