# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abalasub <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 17:26:19 by abalasub          #+#    #+#              #
#    Updated: 2024/05/17 14:12:22 by abalasub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc

CFLAGS = -Wall -Werror -Wextra -O3
MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11
LIBFT = ./libft/libft.a
PRINTF = ./ft_printf/libftprintf.a

SRC = main.c \
      fractals.c \
      display.c \
      event_hook.c \
      convert_tod.c \
      check.c \

all: $(NAME)

$(NAME): $(SRC:.c=.o)
	$(MAKE) --no-print-directory -C ./libft
	echo "\033[1m => 𝙇𝙄𝘽𝙁𝙏 𝙀𝙎𝙏 𝘾𝙊𝙈𝙋𝙄𝙇𝙀́  📚\033[0m"
	$(MAKE) --no-print-directory -C ./ft_printf
	echo "\033[1m => 𝙁𝙏_𝙋𝙍𝙄𝙉𝙏𝙁 𝙀𝙎𝙏 𝘾𝙊𝙈𝙋𝙄𝙇𝙀́  📚\033[0m"
	$(MAKE) --no-print-directory -C ./minilibx-linux
	echo "\033[1m => 𝙈𝙄𝙉𝙄𝙇𝙄𝘽𝙓 𝙀𝙎𝙏 𝘾𝙊𝙈𝙋𝙄𝙇𝙀́ 🎨\033[0m"
	$(CC) $(CFLAGS) -lm $(SRC) $(LIBFT) $(PRINTF) $(MLXFLAGS) -o $(NAME)
	echo "\033[1m => 𝙁𝙍𝘼𝘾𝙏-𝙊𝙇 𝙀𝙎𝙏 𝙋𝙍𝙀̂𝙏 🌀\033[0m"

clean:
	rm -rf $(SRC:.c=.o)
	echo "🔴 𝗧𝗢𝗨𝗦 𝗟𝗘𝗦 𝗢𝗕𝗝𝗘𝗧𝗦 𝗢𝗡𝗧 𝗘́𝗧𝗘́ 𝗦𝗨𝗣𝗣𝗥𝗜𝗠𝗘́ 🚮"

fclean: clean
	rm -rf $(NAME)
	echo "🔴 𝙁𝙍𝘼𝘾𝙏-𝙊𝙇 𝘼 𝙀́𝙏𝙀́ 𝙎𝙐𝙋𝙋𝙍𝙄𝙈𝙀́ 🚮"

re: fclean all

.PHONY: all, clean, fclean, re

.SILENT:
