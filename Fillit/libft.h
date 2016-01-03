/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcalime <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:36:46 by pcalime           #+#    #+#             */
/*   Updated: 2016/01/03 03:09:35 by pcalime          ###   ########.fr       */
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
void			ft_grow_tab(char ***tab, int size);

int				ft_resolve(t_tetrimini *tab_pie, char ***tab, int nb, int end);
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
int				ft_put_rever_verti_pipe(char ***tab, t_tetrimini tab_piece);
int				ft_put_left_t(char ***tab, t_tetrimini tab_piece);
int				ft_put_ship(char ***tab, t_tetrimini tab_piece);

void			ft_putstr(char const *str);
void			ft_putchar(char c);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *str);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strndup(const char *s1, size_t len);
char			*ft_strsub(char const *s, unsigned int start, size_t len);

#endif
