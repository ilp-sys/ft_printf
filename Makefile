# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 16:30:39 by jiwahn            #+#    #+#              #
#    Updated: 2022/07/19 11:50:07 by jiwahn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = -rcs

OBJDIR = ./obj/
LIBFTDIR = ./libft/

SRCS : ft_printf.c \
	ft_printf_utils.c \
	ft_printf_check.c \
	ft_printf_conversion1.c \
	ft_printf_conversion2.c \
	ft_printf_print_numbers.c \
	ft_printf_print_numbers_utils.c

all : $(NAME)

$(NAME) = $(OBJS)
