/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_number.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:56:45 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/18 12:47:29 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*print_numbers(char *str, long num, int base, t_info info)
{
	int		i;
	char	c;
	char	sign;
	char	locase;
	char	tmp[66];

	print_numbers_set_flag(&c, &sign, base, &info);
	print_numbers_set_sign(&sign, num, t_info info);
	tmp = print_numbers_get_digits(num, base, locase);
	str = print_numbers_fill_str1(str, tmp, sign, info);
	str = print_numbers_fill_str2(str, tmp, c, info);
	return (str);
}
