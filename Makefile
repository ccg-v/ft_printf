# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccarrace <ccarrace@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/29 22:17:08 by ccarrace          #+#    #+#              #
#    Updated: 2022/08/22 21:27:15 by ccarrace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -MMD -Wall -Wextra -Werror

HEADER = ft_printf.h

SRC_FILES = ft_print_char.c \
	  		ft_print_nbr.c \
			ft_print_uint.c \
			ft_print_hex.c \
			ft_print_ptr.c \
			ft_printf.c

OBJ_FILES = $(SRC_FILES:.c=.o)

DEP_FILES = $(OBJ_FILES:.o=.d)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar -rcs $(NAME) $(OBJ_FILES)

%.o: %.c
	${CC} -c ${CFLAGS}  $< -o $@
	
clean:
	rm -f $(OBJ_FILES) $(DEP_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all	

.PHONY: clean fclean all re

-include $(DEP_FILES)

