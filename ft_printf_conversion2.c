/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:42:22 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/15 22:43:00 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	conversion_p(t_info info, va_list *args)
{
	int	base;
	int	printed;

	base = 16;
	if (info.width == -1)
	{
		info.width = 2 * sizeof(void *);
		info.flag |= ZEROPAD;
	}
	printed = print_numbers((unsigned long)va_arg(*args, void *, base, info));
	return (printed);
}

int	conversion_int(t_info info, va_list *args)
{
	return (print_numbers(va_arg(*args, int), BASE_DEC, info));
}

int	conversion_x(t_info info, va_list *args)
{
	return (print_numbers(va_arg(*args, unsigned int), BASE_HEX, info));
}
