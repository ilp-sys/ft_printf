/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:39:21 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/16 13:16:56 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*conversion_c(char *str, t_info info, va_list *args)
{
	char	c;

	if (!(info.flag & LEFT))
		printed += left_adjust(&info.width);
	c = va_arg(*args, int);
	ft_putchar(c);
	return (str);
}

char	*conversion_s(char *str, t_info info, va_list *args)
{
	int			i;
	int			len;
	const char	*s = va_arg(*arg, char *);

	i = 0;
	len = ft_strnlen(s, info.precision);
	if (!(info.flag & LEFT))
		printed += left_adjust(len, &info.width);
	while (i++ < len)
	{
		ft_putchar(*s++);
	}
	while (len < width--)
	{
		ft_putchar(' ');
	}
	return (str);
}

char	*conversion_percent(char *str)
{
	*str++ = '%';
	return (str);
}
