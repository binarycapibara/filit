# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 20:00:16 by drafe             #+#    #+#              #
#    Updated: 2019/07/07 16:40:01 by fjenae           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = fillit

HEADERS = fillit.h\

SRC = main.c

OBJ = main.o

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -I $(HEADERS) -o main.o -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) -I $(HEADERS) -L libft/ -lft

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all