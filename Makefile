# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/10 13:11:01 by olmatske          #+#    #+#              #
#    Updated: 2025/12/21 18:57:11 by olmatske         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCES = main.c validate.c stack.c swap_push_rotate.c wrapper.c index_sort.c \
	tiny_sort.c sort.c

PRINTF_DIR = ./lib/ft_printf/
PRINTF_LIB = $(PRINTF_DIR)libftprintf.a

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -fsanitize=address -I./lib  #-Wall -Werror -Wextra
RM = rm -rf

all: $(NAME)

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

$(NAME): $(PRINTF_LIB) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(PRINTF_LIB) -o $(NAME)

%.o: %.c pushswap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	make -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(PRINTF_DIR) fclean

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re