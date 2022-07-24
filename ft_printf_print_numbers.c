/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_number.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:56:45 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/20 09:31:12 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str	print_numbers(t_str buf, long num, int base, t_info info)
{
	char	*tmp;
	t_chars	chars;

	print_numbers_set_flag(&chars, base, &info);
	print_numbers_set_sign(&chars, &num, &info);
	tmp = print_numbers_get_digits(num, base, &chars, info);
	buf = print_numbers_fill_str(buf, tmp, chars, info);
	free(tmp);
	return (buf);
}
