/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:55:33 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/18 12:50:43 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	skip_atoi(const char ***s)
{
	int	i;

	i = 0;
	while (ft_isdigit(***s))
	{
		i = i * 10 + ***s - '0';
		(**s)++;
	}
	return (i);
}

char	*set_width(char *str, int len, char c, int *width)
{
	while (len < *width--)
		*str++ = c;
	return (str);
}

int	do_div(unsigned long *n, unsigned long base)
{
	int	res;

	res = *n % base;
	*n /= base;
	return (res);
}
