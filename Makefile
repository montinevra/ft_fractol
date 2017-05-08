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
SRC = main.c fractol.c mlx_driver.c mlx_handlers.c draw.c julia.c
OBJ = $(SRC:.c=.o) 
CFLAGS = -Wall -Wextra -Werror
LIBDIR = -L./libft -L./minilibx_macos
LIBS = -lft -lmlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re


all: $(NAME)


$(NAME): $(SRC) libft/libft.a minilibx_macos/libmlx.a fractol.h 
	$(CC) -o $(NAME) $(SRC) $(CFLAGS) $(LIBDIR) $(LIBS)

libft/libft.a:
	make -C ./libft

minilibx_macos/libmlx.a:
	make -C ./minilibx_macos

clean:
	make clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

lclean:
	make fclean -C ./libft
	make clean -C ./minilibx_macos

re: fclean all


alloc: $(SRC) libft/libft.a minilibx_macos/libmlx.a fractol.h
	$(CC) -o $(NAME) ~/alloc-wrap.c $(SRC) $(CFLAGS) $(LIBDIR) $(LIBS)


asan: $(SRC) libft/libft.a minilibx_macos/libmlx.a fractol.h
	$(CC) -o $(NAME) $(SRC) $(CFLAGS) $(LIBDIR) $(LIBS) -fsanitize=address
