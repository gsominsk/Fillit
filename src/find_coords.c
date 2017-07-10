/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_coords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 16:49:10 by gsominsk          #+#    #+#             */
/*   Updated: 2016/12/18 16:49:12 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_num_el(char *str)
{
	int num_elem;
	int str_len;

	str_len = 0;
	num_elem = 0;
	while (str[++str_len])
		if (str[str_len] == '\n' && str[str_len + 1] == '\n')
			num_elem++;
	if (str[0] != '\0')
		num_elem++;
	return (num_elem);
}

void	ft_enter_coord(t_fill_cords *p, int x, int y, int col_elem)
{
	if (col_elem == 0)
	{
		p->s1[0] = x;
		p->s1[1] = y;
	}
	else if (col_elem == 1)
	{
		p->s2[0] = x;
		p->s2[1] = y;
	}
	else if (col_elem == 2)
	{
		p->s3[0] = x;
		p->s3[1] = y;
	}
	else
	{
		p->s4[0] = x;
		p->s4[1] = y;
	}
	p->use = 0;
}

void	ft_find_elem_buff(char *str, t_fill_cords *coord, int row, int col)
{
	int				str_len;
	int				col_elem;
	int				elem;

	str_len = -1;
	col_elem = 0;
	elem = 0;
	while (str[++str_len])
	{
		if (str[str_len] == '\n')
		{
			row++;
			col = 0;
			str_len++;
		}
		if (str[str_len] == '\n' && str[str_len - 1] == '\n')
			change(&row, &col_elem, &str_len, &elem);
		if (str[str_len] == '#')
		{
			ft_enter_coord(&coord[elem], col, row, col_elem);
			coord[elem].character = 'A' + elem;
			col_elem++;
		}
		col++;
	}
}

int		ft_find_elem(char *str, t_fill_cords *coord)
{
	int row;
	int col;

	row = 0;
	col = 0;
	ft_find_elem_buff(str, coord, row, col);
	return (ft_num_el(str));
}
