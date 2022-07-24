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

t_str	set_width(t_str buf, int len, char c, int *width)
{
	while (len < (*width)--)
		buf = append_char_to_buf(buf, c);
	return (buf);
}

// TODO - change retern type int to size_t
int	do_div(long *n, long base)
{
	int	res;

	res = (unsigned long)*n % base;
	*n = (unsigned long)*n / base;
	return (res);
}

// TODO - errno when allocation fails
void	check_buf(t_str *buf)
{
	void	*ptr;
	void	*new_ptr;

	if (buf->len == 0)
		return ;
	else if (buf->len % BUFSIZE == 0)
	{
		ptr = buf->str;
		new_ptr = (char *)malloc(sizeof(char) * buf->len * 2);
		if (!new_ptr)
			return ;
		ft_memcpy(new_ptr, ptr, buf->len);
		buf->str = new_ptr;
		free(ptr);
	}
	else
		return ;
}

t_str	append_char_to_buf(t_str buf, char c)
{
	buf.str[buf.len++] = c;
	check_buf(&buf);
	return (buf);
}
