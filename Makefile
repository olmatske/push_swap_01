# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/10 13:11:01 by olmatske          #+#    #+#              #
#    Updated: 2025/11/19 14:49:07 by olmatske         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCES = main.c swapandpush.c rotate.c 

PRINTF_DIR = ./lib/ft_printf
PRINTF = ./lib/ft_printf/libftprintf

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
INCLUDE = lib/ft_printf.h
LIB = lib/ft_printf/libftprintf.a

all: $(NAME)

$(FT_PRINTF) :
	make -C ./lib/ft_printf

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(LIB) -o $(NAME) $(INCLUDE) $(OBJECTS)

%.o: %.c pushswap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re