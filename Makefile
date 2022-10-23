# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlarrieu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 16:35:42 by jlarrieu          #+#    #+#              #
#    Updated: 2022/10/21 16:55:44 by jlarrieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= main.c			\
			  src/read_file.c	\
			  src/keyboard.c	\
			  src/error.c		\
			  src/draw.c		\
			  src/utils.c		\
			  src/color.c		\
			  src/init.c		\
			  src/graphic.c		\
			  src/mouse.c		\
			  src/print_menu.c

INCLUDE		= include/
MLX			= minilibx-linux/
LIBFT		= libft/
CFLAGS		= -Werror -Wextra -Wall -g
MLX_FLAGS	= -lm -lmlx -lX11 -lXext
NAME		= fdf
LIB			= libft/libft.a minilibx-linux/libmlx_Linux.a

BGreen		= '\033[1;32m'
NC			= '\033[0m'

all:
	@make -sC $(LIBFT) all
	@echo ${BGreen}Compiling libft finished !${NC}
	@make -sC $(MLX) all
	@echo ${BGreen}Compiling MLX finished !${NC}
	@gcc $(SRC) -o $(NAME) $(LIB) $(CFLAGS) $(MLX_FLAGS) -L$(MLX) -I$(INCLUDE)
	@echo $(BGreen)Compiling FDF finished !$(NC)

clean:
	@make -sC $(LIBFT) clean
	@make -sC $(MLX) clean

fclean: clean
	rm -f $(NAME)
	@make -sC $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
