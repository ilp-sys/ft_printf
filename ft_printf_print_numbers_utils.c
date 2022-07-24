/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_numbers_utils.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:51:02 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/20 11:40:36 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_numbers_set_flag(t_chars *chars, int base, t_info *info)
{
	chars->locase = (info->flag & SMALL);
	if (info->flag & LEFT)
		info->flag &= ~ZEROPAD;
	else if (info->precision != -1)
		info->flag &= ~ZEROPAD;
	if (info->flag & ZEROPAD)
		chars->c = '0';
	else
		chars->c = ' ';
	if (info->flag & SPECIAL && !(info->flag & NULLIFY))
	{
		if (base == BASE_HEX)
			info->width -= 2;
	}
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

char	*print_numbers_get_digits(long num, int base, \
		t_chars *chars, t_info info)
{
	int					i;
	char				*tmp;
	const char	digits[16] = "0123456789ABCDEF";

	i = 0;
	tmp = (char *)malloc(sizeof(char) * 20);
	if (tmp)
	{
		if (num == 0 && !(info.precision == 0))
			tmp[i++] = '0';
		else if (num != 0)
		{
			while (num != 0)
				tmp[i++] = (digits[do_div(&num, base)] | chars->locase);
		}
		tmp[i] = '\0';
	}
	return (tmp);
}

t_str	print_numbers_fill_str(t_str buf, char *tmp, \
		t_chars chars, t_info info)
{
	int	i;

	i = ft_strlen(tmp);
	if (i > info.precision)
		info.precision = i;
	info.width -= info.precision;
	if (!(info.flag & (ZEROPAD + LEFT)))
		buf = set_width(buf, 0, ' ', &info.width);
	if (chars.sign)
		buf = append_char_to_buf(buf, chars.sign);
	if (info.flag & SPECIAL && !(info.flag & NULLIFY))
	{
		buf = append_char_to_buf(buf, '0');
		buf = append_char_to_buf(buf, 'X' | chars.locase);
	}
	if (!(info.flag & LEFT))
		buf = set_width(buf, 0, chars.c, &info.width);
	while (i < info.precision--)
		buf = append_char_to_buf(buf, '0');
	while (i-- > 0)
		buf = append_char_to_buf(buf, tmp[i]);
	while (info.width-- > 0)
		buf = append_char_to_buf(buf, ' ');
	return (buf);
}
