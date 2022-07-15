/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 21:55:33 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/15 22:32:30 by jiwahn           ###   ########.fr       */
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

int	left_adjust(int *width)
{
	int	printed;

	printed = 0;
	while (--(*width) > 0)
	{
		ft_putchar(' ');
		printed++;
	}
	return (printed);
}
