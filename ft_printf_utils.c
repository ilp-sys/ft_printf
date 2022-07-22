/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:55:33 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/19 20:03:53 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	while (len < (*width)--)
		*str++ = c;
	return (str);
}

int	do_div(long *n, long base)
{
	int	res;

	res = (unsigned long)*n % base;
	*n = (unsigned long)*n / base;
	return (res);
}
