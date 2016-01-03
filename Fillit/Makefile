# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcalime <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/05 14:04:20 by pcalime           #+#    #+#              #
#    Updated: 2016/01/03 02:05:40 by pcalime          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c ft_putstr.c ft_putchar.c ft_counttetri.c ft_checkcolonne.c\
	  ft_putnbr.c ft_read.c ft_strcpy.c ft_recup.c ft_no_newline.c\
	  ft_split_piece.c ft_strndup.c ft_strlen.c ft_recup_tetri.c\
	  ft_atoi.c ft_isdigit.c ft_strsub.c ft_strncpy.c ft_check_tetri.c\
	  ft_check_piece.c ft_remove_piece.c ft_put_all.c ft_put_tetris.c\
	  ft_put_tetris_2.c ft_put_tetris_3.c ft_put_tetris_4.c\
	  ft_create_square.c ft_resolve.c ft_affich_tab.c ft_size.c

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
