# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apidgeot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/16 12:54:59 by apidgeot          #+#    #+#              #
#    Updated: 2019/12/16 14:43:45 by apidgeot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

CC=gcc

CFLAGS=-Wall -Wextra -Werror

SRCS=main.c reader.c solver.c map.c tetri.c

OBJ=$(SRCS:.c=.o)

all: 
	@$(MAKE) -C libft
	@$(MAKE) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -I ./ -c $(SRCS)
	@ar rc $(NAME) $(OBJ)
	@ranfil $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
