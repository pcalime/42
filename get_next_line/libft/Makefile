# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcalime <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/30 19:25:23 by pcalime           #+#    #+#              #
#    Updated: 2016/02/01 16:37:58 by pcalime          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
	  ft_isspace.c ft_bzero.c ft_atoi.c ft_memalloc.c ft_memccpy.c ft_memchr.c\
	  ft_memcmp.c ft_memdel.c ft_memcpy.c ft_memmove.c ft_memalloc.c\
	  ft_memset.c ft_tolower.c ft_strtrim.c ft_strstr.c ft_strnstr.c \
	  ft_strncpy.c ft_putchar.c ft_toupper.c ft_strcat.c ft_strchr.c\
	  ft_bzero.c ft_memccpy.c ft_memchr.c ft_strlen.c ft_strdup.c \
	  ft_strncpy.c ft_strncat.c ft_strchr.c ft_strcpy.c ft_strrchr.c\
	  ft_strcmp.c ft_strncmp.c ft_strlcat.c ft_strnew.c ft_strdel.c \
	  ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	  ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
	  ft_itoa.c ft_strsplit.c ft_putchar_fd.c ft_putnbr.c ft_putnbr_fd.c\
	  ft_putstr.c ft_putstr_fd.c ft_putendl.c ft_putendl_fd.c ft_strndup.c\
	  ft_countwords.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re: fclean all
