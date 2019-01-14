# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvan-erp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/04 20:50:47 by pvan-erp          #+#    #+#              #
#    Updated: 2017/04/04 20:50:49 by pvan-erp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol 
CC = gcc 
SRC = main.c fractol.c sdl_driver.c sdl_handlers.c draw.c julia.c
OBJ = $(SRC:.c=.o) 
CFLAGS = -Wall -Wextra -Werror `sdl2-config --cflags --libs`

.PHONY: all clean fclean re


all: $(NAME)


$(NAME): $(SRC)
	$(CC) -o $(NAME) $(SRC) $(CFLAGS) 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

