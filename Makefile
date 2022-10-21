
GNL		= gnl/get_next_line_bonus.c /
			gnl/get_next_line_utils_bonus.c 

SRC		= src/fdf.c 

INCLUDE = include/
FLAGS	= -Werror -Wextra -Wall
NAME	= fdf
LIB		= libft/libft.a #minilibx_linux/libmlx.a

all:
	@make -C libft/ all
	@make -C minilibx_linux/ all
	gcc $(SRC) -o $(NAME) $(FLAGS) $(LIB) -I$(INCLUDE)

clean:
	@make -C libft/ clean
	@make -C minilibx_linux/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
