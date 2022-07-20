/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:42:22 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/20 10:20:06 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*conversion_p(char *str, t_info info, va_list args)
{
	void	*p;

	if (info.width == -1)
	{
		info.width = 2 * sizeof(void *);
		info.flag |= ZEROPAD;
	}
	p = (long)va_arg(args, void *);
	str = print_numbers(str, p, BASE_HEX, info);
	return (str);
}

char	*conversion_int(char *str, t_info info, va_list args)
{
	if (info.flag & SIGN)
		str = print_numbers(str, va_arg(args, int), BASE_DEC, info);
	else
		str = print_numbers(str, va_arg(args, unsigned int), BASE_DEC, info);
	return (str);
}

char	*conversion_x(char *str, t_info info, va_list args)
{
	if (info.flag & SIGN)
		str = print_numbers(str, va_arg(args, int), BASE_HEX, info);
	else
		str = print_numbers(str, va_arg(args, unsigned int), BASE_HEX, info);
	return (str);
}
