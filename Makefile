# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 20:00:16 by drafe             #+#    #+#              #
#    Updated: 2019/07/08 14:46:05 by fjenae           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

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

# CC = gcc

# CFLAGS = -Wall -Wextra -Werror -g

# NAME = fillit

# HEADERS = fillit.h\

# # SRC = main.c

# # OBJ = main.o

# all: $(NAME)

# $(NAME):
# 	@$(CC) $(CFLAGS) -I $(HEADERS) -c main.c algorithm.c
# 	@$(CC) -o $(NAME) main.o algorithm.o -I $(HEADERS) -L libft/ -lft

# clean:
# 	@rm -rf $(OBJ)

# fclean: clean
# 	@rm -f $(NAME)

# re: fclean all