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

int	conversion_c(t_info info, va_list *args)
{
	char	c;
	int		printed;

	printed = 0;
	if (!(info.flag & LEFT))
		printed += left_adjust(&info.width);
	c = va_arg(*args, int);
	ft_putchar(c);
	printed++;
	return (printed);
}

int	conversion_s(t_info info, va_list *args)
{
	int			i;
	int			len;
	int			printed;
	const char	*s = va_arg(*arg, char *);

	i = 0;
	printed = 0;
	len = ft_strnlen(s, info.precision);
	if (!(info.flag & LEFT))
		printed += left_adjust(len, &info.width);
	while (i++ < len)
	{
		ft_putchar(*s++);
		printed++;
	}
	while (len < width--)
	{
		ft_putchar(' ');
		printed++;
	}
	return (printed);
}

int	conversion_percent()
{
	ft_putchar('%');
	return (1);
}
