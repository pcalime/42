# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcalime <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/21 17:25:48 by pcalime           #+#    #+#              #
#    Updated: 2016/03/15 18:15:46 by pcalime          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = ft_draw_fdf.c ft_fill_tab_int.c ft_read_file.c fdf.c ft_draw_line.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc -Wall -Wextra -Werror $(OBJ) -o $(NAME) -lft -L ./libft -lmlx -framework OpenGL -framework AppKit

%.o:%.c
	gcc -c -Wall -Wextra -Werror $< -o $@ -Iincludes
clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all
