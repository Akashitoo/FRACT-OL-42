# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abalasub <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 09:23:23 by abalasub          #+#    #+#              #
#    Updated: 2024/04/19 19:36:30 by abalasub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_printf.c ft_printf_c.c ft_printf_s.c ft_printf_d.c \
			ft_printf_u.c ft_printf_hex.c ft_printf_p.c

BONUS		=

OBJS		= $(SRCS:.c=.o)

CC              = cc
RM              = rm -f
CFLAGS          = -Wall -Wextra -Werror -I.

NAME		=	libftprintf.a

all:		$(NAME)

$(NAME):	$(OBJS)	
		ar rcs $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re

.SILENT:
