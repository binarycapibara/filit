# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 20:00:16 by drafe             #+#    #+#              #
#    Updated: 2019/07/08 16:52:57 by fjenae           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

NAME = fillit

HEADERS = fillit.h libft/libft.h

SRC = main.c algorithm.c

OBJ = main.o algorithm.o

all: $(NAME)

$(NAME):
	@$(CC) -c -I $(HEADERS) $(CFLAGS) $(SRC)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L libft/ -lft

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