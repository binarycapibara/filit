#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drafe <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 20:00:16 by drafe             #+#    #+#              #
#    Updated: 2019/06/07 21:10:23 by drafe            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = fillit

HEADERS = get_next_line.h\

SRC = main.c

OBJ = get_next_line.o\
	main.o

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -I $(HEADERS) -o get_next_line.o -c get_next_line.c
	@$(CC) $(CFLAGS) -I $(HEADERS) -o main.o -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) -I $(HEADERS) -L libft/ -lft

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
