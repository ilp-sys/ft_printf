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

char	*conversion_p(char *str, t_info info, va_list args)
{
	void	*p;

	info.flag |= (SPECIAL + SMALL);
	p = va_arg(args, void *);
	str = print_numbers(str, (uintptr_t)p, BASE_HEX, info);
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
	long	num;

	if (info.flag & SIGN)
		num = va_arg(args, int);
	else
		num = va_arg(args, unsigned int);
	if (num == 0)
		info.flag |= NULLIFY;
	str = print_numbers(str, num, BASE_HEX, info);
	return (str);
}
