# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcalime <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/21 17:25:48 by pcalime           #+#    #+#              #
#    Updated: 2016/02/23 19:22:52 by pcalime          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf.c ft_draw_line.c libft/libft.a get_next_line.c

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror $(SRC) -o $(NAME) -lmlx -framework OpenGL -framework AppKit

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
