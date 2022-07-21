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

char	*conversion_c(char *str, t_info info, va_list args)
{
	if (!(info.flag & LEFT))
		while (--info.width > 0)
			*str++ = ' ';
	*str++ = va_arg(args, int);
	while (--info.width > 0)
		*str++ = ' ';
	return (str);
}

char	*conversion_s(char *str, t_info info, va_list args)
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
			*str++ = ' ';
	while (i++ < len)
		*str++ = *s++;
	while (len < info.width--)
		*str++ = ' ';
	return (str);
}

char	*conversion_percent(char *str)
{
	*str++ = '%';
	return (str);
}
