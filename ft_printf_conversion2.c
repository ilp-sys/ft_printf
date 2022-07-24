/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 22:42:22 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/20 11:44:17 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str	conversion_p(t_str buf, t_info info, va_list args)
{
	void	*p;

	info.flag |= (SPECIAL + SMALL);
	p = va_arg(args, void *);
	buf = print_numbers(buf, (uintptr_t)p, BASE_HEX, info);
	return (buf);
}

t_str	conversion_int(t_str buf, t_info info, va_list args)
{
	if (info.flag & SIGN)
		buf = print_numbers(buf, va_arg(args, int), BASE_DEC, info);
	else
		buf = print_numbers(buf, va_arg(args, unsigned int), BASE_DEC, info);
	return (buf);
}

t_str	conversion_x(t_str buf, t_info info, va_list args)
{
	long	num;

	if (info.flag & SIGN)
		num = va_arg(args, int);
	else
		num = va_arg(args, unsigned int);
	if (num == 0)
		info.flag |= NULLIFY;
	buf = print_numbers(buf, num, BASE_HEX, info);
	return (buf);
}
