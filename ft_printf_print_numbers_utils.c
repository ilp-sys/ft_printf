/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_numbers_utils.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:51:02 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/19 12:57:48 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	print_numbers_set_flag(char *c, \
		char *locase, int base, t_info *info)
{
	*locase = (info->flag & SMALL);
	if (info->flag & LEFT)
		info->flag &= ~ZEROPAD;
	if (info->flag == '0')
		*c = '0';
	else
		*c = ' ';
	if (info->flag & SPECIAL)
		if (base == BASE_HEX)
			info->width -= 2;
}

static void	print_numbers_set_sign(char *sign, long num, t_info *info)
{
	*sign = 0;
	if (info->flag & SIGN)
	{
		if (num < 0)
		{
			*sign = '-';
			num = -num;
			info->width--;
		}
		else if (info->flag & PLUS)
		{
			*sign = '+';
			info->width--;
		}
		else if (info->flag & SPACE)
		{
			*sign = ' ';
			info->width--;
		}
	}
}

static char	*print_numbers_get_digits(long num, int base, int locase)
{
	int					i;
	char				*tmp;
	static const char	digits[16] = "0123456789ABCDEF";

	i = 0;
	tmp = (char *)malloc(sizeof(char) * 66);
	if (num == 0)
		tmp[i++] = '0';
	else
		while (num != 0)
			tmp[i++] = (digits[do_div(&num, base)] | locase);
	tmp[i] = '\0';
	return (tmp);
}

static char	*print_numbers_fill_str1(char *str, char *tmp, \
		char sign, t_info info)
{
	int	i;

	i = ft_strlen(tmp);
	if (i > info.precision)
		info.precision = i;
	info.width -= info.precision;
	if (!(info.flag & (ZEROPAD + LEFT)))
		str = set_width(str, 0, ' ', &info.width);
	if (sign)
		*str++ = sign;
	if (info.flag & SPECIAL)
	{
		*str++ = '0';
		*str++ = ('X' | locase);
	}
	return (str);
}

static char	*print_numbers_fill_str2(char *str, char *tmp, char c, t_info info)
{
	int	i;

	i = ft_strlen(tmp);
	if (!(info.flag & LEFT))
		str = set_width(str, 0, c, &info.width);
	while (i < info.precision--)
		*str++ = '0';
	while (i-- > 0)
		*str++ = tmp[i];
	while (info.width-- > 0)
		*str++ = ' ';
	return (str);
}
