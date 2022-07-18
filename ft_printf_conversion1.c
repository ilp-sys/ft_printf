/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:39:21 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/18 12:10:56 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*conversion_c(char *str, t_info info, va_list *args)
{
	char	c;

	if (!(info.flag & LEFT))
		str = set_width(str, 0, ' ', &info.width);
	*str++ = va_arg(*args, int);
	str = set_width(str, 0, ' ', &info.width);
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
		str = set_width(str, len, ' ', &info.width);
	ft_strncat(str, s, len);
	str = set_width(str, len, ' ', &info.width);
	return (str);
}

char	*conversion_percent(char *str)
{
	*str++ = '%';
	return (str);
}
