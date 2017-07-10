/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:47:10 by emasiuk           #+#    #+#             */
/*   Updated: 2016/12/18 17:47:11 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_fill_cords
{
	int				s1[2];
	int				s2[2];
	int				s3[2];
	int				s4[2];
	int				use;
	char			character;
	int				elem_static;
	int				min_f;
}					t_fill_cords;

char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_putstr(char *str);
void				ft_putchar(char c);
size_t				ft_strlen(const char *s);

short				validate_near(t_fill_cords *p, int i);
short				validate_file(char *str, int num_elem);
short				validate_block(char *str);
short				validate_elem(char *str);
short				validate_fig_ang(t_fill_cords *p, int elem, char *str);
short				validate_fig(t_fill_cords *p, int i);
short				check_some_figure(t_fill_cords *p, int i);

void				write_fig(char **map, int x, int y, t_fill_cords *p);
void				del_fig(char **map, int y, int x, t_fill_cords *p);
void				obnulit(int elem, t_fill_cords *coord);
void				show_map(char **map);
void				ft_enter_coord(t_fill_cords *p, int x, int y, int col_elem);
void				change(int *row, int *col_elem, int *str_len, int *elem);
void				ft_find_elem_buff(char *str, t_fill_cords *coord,
										int row, int col);

char				**create_map(int elem, t_fill_cords *coord, char *str);
char				*ft_find_file(char *file_name, char *str);

int					func_error(void);
int					valid_place(char **map, int x, int y, t_fill_cords *p);
int					change_fig(char **map, int x, int y, t_fill_cords *p,
								int elem);
int					fill_map(char **map, t_fill_cords *p, int k);
int					min_field(int elem, t_fill_cords *p);
int					add(int *col, int *row, int *str_len);
int					ft_find_elem(char *str, t_fill_cords *coord);
int					ft_num_el(char *str);

#endif
