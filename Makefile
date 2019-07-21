# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drafe <drafe@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 20:00:16 by drafe             #+#    #+#              #
#    Updated: 2019/07/19 19:59:02 by drafe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = fillit

HEADERS = fillit.h\
	libft/libft.h

OBJ = main.o\
	algorithm.o\
	placement.o\
	ft_valid.o\
	ft_save_shape.o

SRC = main.c\
	algorithm.c\
    placement.c\
    ft_valid.c\
    ft_save_shape.c

all: $(NAME)

$(NAME):
	@make -C libft/
	@$(CC) -c -I $(HEADERS) $(CFLAGS) $(SRC)
	@gcc $(CFLAGS) $(OBJ) -o $(NAME) -L libft/ -lft

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

