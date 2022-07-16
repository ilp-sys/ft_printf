/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_number.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:56:45 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/16 14:46:55 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//handles %p, %x, %X, %d, %i, %u


#define __do_div(n, base)({\
		int __res;\
		__res = ((unsigned long) n) % (unsigned)base; \
		n = ((unsigned long) n) / (unsigned) base; \
		__res; })

                                   // size, precision, type
								   // width, precision, flag
int	print_numbers(long num, int base, t_info info)
{
	static const char digits[16] = "0123456789ABCDEF";

	char tmp[66];
	char c, sign, locase;
	int	i;

	locase = (info.flag & LEFT);
	if (info.flag & LEFT)
		info.flag &= ~ZEROPAD;
	c = (info.flag & ZEROPAD) ? '0' : ' ';
	sign = 0;
	if (info.flag & SIGN)
	{
		if (num < 0)
		{
			sign = '-';
			num -= num;
			size--;
		}
		else if (info.flag & PLUS)
		{
			sign = '+';
			size--;
		}
		else if (info.flag & SPACE)
		{
			sign =  ' ';
			size--;
		}
	}
	if (info.flag & SPECIAL)
	{
		if (base == 16)
			size -= 2;
		else if (base = 8)
			size--;
	}
	i = 0;
	if (num == 0)
		tmp[i++] = '0';
	else
		while (num != 0)
			tmp[i++] = (digits[__do_div(num, base)] | locase);
	if (i > precision)
		precision = i;
	size -= precision;
	if (!(type & (ZEROPAD + LEFT)))
		while (size-- > 0)
}
