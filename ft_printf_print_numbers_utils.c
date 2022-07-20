/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_numbers_utils.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:51:02 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/20 09:31:39 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_numbers_set_flag(t_chars *chars, int base, t_info *info)
{
	chars->locase = (info->flag & SMALL);
	if (info->flag & LEFT)
		info->flag &= ~ZEROPAD;
	if (info->flag & ZEROPAD)
		chars->c = '0';
	else
		chars->c = ' ';
	if (info->flag & SPECIAL)
		if (base == BASE_HEX)
			info->width -= 2;
}

void	print_numbers_set_sign(t_chars *chars, long *num, t_info *info)
{
	chars->sign = 0;
	if (info->flag & SIGN)
	{
		if (*num < 0)
		{
			chars->sign = '-';
			*num = -(*num);
			info->width--;
		}
		else if (info->flag & PLUS)
		{
			chars->sign = '+';
			info->width--;
		}
		else if (info->flag & SPACE)
		{
			chars->sign = ' ';
			info->width--;
		}
	}
}

char	*print_numbers_get_digits(long num, int base, t_chars *chars)
{
	int					i;
	char				*tmp;
	static const char	digits[16] = "0123456789ABCDEF";

	i = 0;
	tmp = (char *)malloc(sizeof(char) * 66);
	if (!tmp)
		return (NULL);
	if (num == 0)
		tmp[i++] = '0';
	else
		while (num != 0)
			tmp[i++] = (digits[do_div(&num, base)] | chars->locase);
	tmp[i] = '\0';
	return (tmp);
}

char	*print_numbers_fill_str(char *str, char *tmp, \
		t_chars chars, t_info info)
{
	int	i;

	i = ft_strlen(tmp);
	if (i > info.precision)
		info.precision = i;
	info.width -= info.precision;
	if (!(info.flag & (ZEROPAD + LEFT)))
		str = set_width(str, 0, ' ', &info.width);
	if (chars.sign)
		*str++ = chars.sign;
	if (info.flag & SPECIAL)
	{
		*str++ = '0';
		*str++ = ('X' | chars.locase);
	}
	if (!(info.flag & LEFT))
		str = set_width(str, 0, chars.c, &info.width);
	while (i < info.precision--)
		*str++ = '0';
	while (i-- > 0)
		*str++ = tmp[i];
	while (info.width-- > 0)
		*str++ = ' ';
	return (str);
}
