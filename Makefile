# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abalasub <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 17:26:19 by abalasub          #+#    #+#              #
#    Updated: 2024/03/04 13:59:47 by abalasub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc

CFLAGS = -Wall -Werror -Wextra -O3
MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11
LIBFT = ./libft/libft.a
PRINTF = ./ft_printf/libftprintf.a

SRC = main.c \
      fractales.c \
      display.c \
      event_hook.c \
      convert_tod.c \
      check.c \

all: $(NAME)

$(NAME): $(SRC:.c=.o)
	$(MAKE) --no-print-directory -C ./libft
	echo "\033[1m LIBFT ✅\033[0m"
	$(MAKE) --no-print-directory -C ./ft_printf
	echo "\033[1m FT_PRINTF ✅\033[0m"
	$(MAKE) --no-print-directory -C ./minilibx-linux
	echo "\033[1m MiniLibX ✅\033[0m"
	$(CC) $(CFLAGS) -lm $(SRC) $(LIBFT) $(PRINTF) $(MLXFLAGS) -o $(NAME)
	echo "\033[1m FRACT-OL est prêt ✅\033[0m"

clean:
	rm -rf $(SRC:.c=.o)
	echo " OBJ supprimé 🗑️"

fclean: clean
	rm -rf $(NAME)
	echo " $(NAME) supprimé 🗑️"

re: fclean all

.PHONY: all, clean, fclean, re

.SILENT:
