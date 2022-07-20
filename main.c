/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:50:47 by jiwahn            #+#    #+#             */
/*   Updated: 2022/07/20 15:01:23 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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
	/* test3 */
	int a5 = printf("%1c", c);
	printf("\t:Return value: %d\n", a5);
	int a6 = ft_printf("%1c", c);
	printf("\t:Return value: %d\n", a6);
//
//	/* test4 */
//	int a7 = printf("%%");
//	printf("\t Return value: %d\n", a7);
//	int a8 = ft_printf("%%");
//	printf("\t Return value: %d\n", a8);
//
//	/* test5 */
//	int a9 = printf("%d", -12345);
//	printf("\n Return value: %d\n", a9);
//	int a10 = ft_printf("%d", -12345);
//	printf("\n Return value: %d\n", a10);

	/* test6 */
//	int a11 = printf("everywhere %s", NULL);
//	printf("\n Return value: %d\n", a11);
//	int a12 = ft_printf("everywhere %s", NULL);
//	printf("\n Return value: %d\n", a12);

	/* test7 */
//	int a13 = printf("%s", "");
//	printf("\n Return value: %d\n", a13);
//	int a14 = ft_printf("%s", "");
//	printf("\n Return value: %d\n", a14);
//
//	/* test8 */
//	int a15 = printf("%p", &c);
//	printf("\n Return value: %d\n", a15);
//	int a16 = ft_printf("%p", &c);
//	printf("\n Return value: %d\n", a16);
//
	/* test8 */
//	int a17 = printf("%c%c%c*", '\0', '1', 1);
//	printf("\n Return value: %d\n", a17);
//	int a18 = ft_printf("%c%c%c*", '\0', '1', 1);
//	printf("\n Return value: %d\n", a18);
	return 0;
}
