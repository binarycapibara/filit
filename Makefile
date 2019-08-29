# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drafe <drafe@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 20:00:16 by drafe             #+#    #+#              #
#    Updated: 2019/07/25 16:56:22 by drafe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = fillit

HEADERS = fillit.h

OBJS = main.o\
	algorithm.o\
    ft_save_shape.o\
	ft_valid.o\
	placement.o\
	ft_valid_touch.o

SRCS = main.c\
       	algorithm.c\
        ft_save_shape.c\
       	ft_valid.c\
       	placement.c\
       	ft_valid_touch.c

all: $(NAME)

$(NAME):$(OBJS) | lib
	$(CC) $(CFLAGS) -o $(NAME) -L./Libft/ -lft $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

lib:
	make -C./Libft

clean:
	make clean -C./Libft
	rm -rf $(OBJS)

fclean: clean
	make fclean -C./Libft
	rm -f $(NAME)

re: fclean all

