/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:36:46 by pcalime           #+#    #+#             */
/*   Updated: 2016/01/03 02:05:51 by pcalime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define BUF_SIZE 650

typedef	struct	s_tetrimini
{
	char		letter;
	long		forme;
}				t_tetrimini;

int				ft_counttetri(char *str);
int				ft_checkcolonne(char *str);
int				ft_recup(t_tetrimini **tab_piece, char *str, int nb_tetri);
char			*ft_read(char *str);
char			*ft_no_newline(char *str);
char			**ft_split_piece(char *str);
long			ft_atoi(const char *str);
long			ft_check(char *s);
long			ft_recup_tetri(char *s);
int				ft_check_tetri(long n);
int				ft_check_tetri_1(long n);
void			ft_create_square(int end, t_tetrimini *tab_piece);
int				ft_size(int nb);

int				ft_resolve(t_tetrimini *tab_piece, char ***tab_final, int nb, int end);
int				ft_check_piece(t_tetrimini tab_piece, char **tab_final);
int				ft_put_all(t_tetrimini tab_piece, char ***tab_final);
int				ft_put_piece(t_tetrimini tab_piece, char ***tab_final);
int				ft_put_piece_2(t_tetrimini tab_piece, char ***tab_final);
int				ft_put_piece_3(t_tetrimini tab_piece, char ***tab_final);
int				ft_put_piece_4(t_tetrimini tab_piece, char ***tab_final);
void			ft_remove_piece(t_tetrimini tab_piece, char ***tab_final);

void			ft_affich_tab(char **tab_final, int size);

int				ft_put_square(char ***tab, t_tetrimini tab_piece);
int				ft_put_s(char ***tab, t_tetrimini tab_piece);
int				ft_put_vertical_s(char ***tab, t_tetrimini tab_piece);
int				ft_put_t(char ***tab, t_tetrimini tab_piece);
int				ft_put_reversed_s(char ***tab, t_tetrimini tab_piece);
int				ft_put_reversed_vertical_s(char ***tab, t_tetrimini tab_piece);
int				ft_put_reversed_l(char ***tab, t_tetrimini tab_piece);
int				ft_put_l(char ***tab, t_tetrimini tab_piece);
int				ft_put_gun(char ***tab, t_tetrimini tab_piece);
int				ft_put_horiz_i(char ***tab, t_tetrimini tab_piece);
int				ft_put_pipe(char ***tab, t_tetrimini tab_piece);
int				ft_put_reversed_gun(char ***tab, t_tetrimini tab_piece);
int				ft_put_right_t(char ***tab, t_tetrimini tab_piece);
int				ft_put_vertical_pipe(char ***tab, t_tetrimini tab_piece);
int				ft_put_reversed_pipe(char ***tab, t_tetrimini tab_piece);
int				ft_put_i(char ***tab, t_tetrimini tab_piece);
int				ft_put_reversed_vertical_pipe(char ***tab, t_tetrimini tab_piece);
int				ft_put_left_t(char ***tab, t_tetrimini tab_piece);
int				ft_put_ship(char ***tab, t_tetrimini tab_piece);

void			ft_bzero(void *s, size_t n);
void			ft_memdel(void **ap);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memalloc(size_t size);

int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_isspace(int c);

char			*ft_strdup(const char *s);
char			*ft_strndup(const char *s1, size_t len);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);

size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t size);

#endif
