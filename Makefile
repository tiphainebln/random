# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouline <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/30 02:53:28 by tbouline          #+#    #+#              #
#    Updated: 2017/09/30 02:55:05 by tbouline         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
PATH_INC = ./libft/

CC = cc
CFLAGS = -Wall -Wextra -Werror -c -I $(PATH_INC)

LIBS = -lm -L libft/ -lft -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

HEAD = wolf3d.h

SRC =	main.c \
		init.c \
		hooks.c \
		error.c \
		draw.c \
		map.c
		
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
		make -C minilibx_macos/
		make -C libft/
		$(CC) $(OBJ) -o $(NAME) $(LIBS)

.PHONY: clean fclean re

clean:
		make -C libft/ clean
		/bin/rm -f $(OBJ)

fclean: clean
		make -C libft/ fclean
		/bin/rm -f $(NAME)

re: fclean all
