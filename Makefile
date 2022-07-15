 **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 16:50:25 by jiwahn            #+#    #+#              #
#    Updated: 2022/07/15 21:59:01 by jiwahn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = libftprintf.a

SRCS = $(wildcard *.c)
OBJS = $(SRCS.c=.o)

$(NAME) : $(OBJS)
	ar -rcs $@ $^

all : $(NAME)

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : all

.PHONY : all clean fclean re

