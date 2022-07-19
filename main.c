/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:50:47 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/19 17:23:31 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int main()
{
	int intnum = 2147483647;
	char *str = "string";
	char c = 'c';

	/* test1 */
//	int a1 = printf("% 20.5d", intnum);
//	printf("\t Return value: %d\n", a1);
//	int a2 = ft_printf("% 20.5d", intnum);
//	printf("\t Return value: %d\n", a2);
//
//	/* test2 */
//	int a3 = printf("%s", str);
//	printf("\t Return value: %d\n", a3);
//	int a4 = ft_printf("%s", str);
//	printf("\t Return value: %d\n", a4);
//
//	/* test3 */
//	int a5 = printf("%-5c", c);
//	printf("\t Return value: %d\n", a5);
//	int a6 = ft_printf("%-5c", c);
//	printf("\t Return value: %d\n", a6);
//
//	/* test4 */
//	int a7 = printf("%%");
//	printf("\t Return value: %d\n", a7);
//	int a8 = ft_printf("%%");
//	printf("\t Return value: %d\n", a8);
//
	/* test5 */
	int a9 = printf("% 9.7d", 12345);
	printf("\n Return value: %d\n", a9);
	int a10 = printf("% 9.7d", 12345);
	printf("\n Return value: %d\n", a10);

	return 0;
}
