/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:42:22 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/16 13:39:39 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	conversion_p(t_info info, va_list *args)
{
	if (info.width == -1)
	{
		info.width = 2 * sizeof(void *);
		info.flag |= ZEROPAD;
	}
	return (print_numbers((unsigned long)va_arg(*args, void *), BASE_HEX, info));
}

int	conversion_int(t_info info, va_list *args)
{
	if (info.flag & SIGN)
		return (print_numbers(va_arg(*args, unsigned int), BASE_DEC, info));
	return (print_numbers(va_arg(*args, int), BASE_DEC, info));
}

int	conversion_x(t_info info, va_list *args)
{
	if (info.flag & SIGN)
		return (print_numbers(va_arg(*args, unsigned int), BASE_HEX, info));
	return (print_numbers(va_arg(*args, int), BASE_HEX, info));
}
