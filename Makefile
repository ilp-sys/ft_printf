# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 16:30:39 by jiwahn            #+#    #+#              #
#    Updated: 2022/07/19 19:47:33 by jiwahn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = -rcs

RM = rm

LIBFT_DIR = libft/
LIBFT_LIB = libft.a

SRCS =	ft_printf.c ft_printf_utils.c ft_printf_check.c \
		ft_printf_conversion1.c ft_printf_conversion2.c \
		ft_printf_print_numbers.c ft_printf_print_numbers_utils.c

OBJ_DIR = obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all : $(NAME)

clean :
	$(RM) -f $(OBJS)
	$(RM) -rf $(OBJ_DIR)

fclean : clean
	$(RM) -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re : fclean all

bonus : all

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) all
	@cp $(LIBFT_DIR)$(LIBFT_LIB) $@
	$(AR) $(ARFLAGS) $@ $^
	 
$(OBJ_DIR)%.o : %.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) $< -c -o $@

.PHONY : all clean fclean re bonus
