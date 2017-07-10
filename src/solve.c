/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 16:49:56 by gsominsk          #+#    #+#             */
/*   Updated: 2016/12/18 16:49:57 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	write_fig(char **map, int y, int x, t_fill_cords *p)
{
	int n;
	int k;

	n = x - p->s1[0];
	k = y - p->s1[1];
	map[p->s1[1] + k][p->s1[0] + n] = p->character;
	map[p->s2[1] + k][p->s2[0] + n] = p->character;
	map[p->s3[1] + k][p->s3[0] + n] = p->character;
	map[p->s4[1] + k][p->s4[0] + n] = p->character;
	p->use = 1;
}

void	del_fig(char **map, int y, int x, t_fill_cords *p)
{
	int n;
	int k;

	n = x - p->s1[0];
	k = y - p->s1[1];
	map[p->s1[1] + k][p->s1[0] + n] = '.';
	map[p->s2[1] + k][p->s2[0] + n] = '.';
	map[p->s3[1] + k][p->s3[0] + n] = '.';
	map[p->s4[1] + k][p->s4[0] + n] = '.';
	p->use = 0;
}

int		valid_place(char **map, int y, int x, t_fill_cords *p)
{
	int n;
	int k;

	n = x - p->s1[0];
	k = y - p->s1[1];
	if ((p->s1[1] + k) >= p[0].min_f || (p->s1[0] + n) >= p[0].min_f)
		return (0);
	else if ((p->s2[1] + k) >= p[0].min_f || (p->s2[0] + n) >= p[0].min_f)
		return (0);
	else if ((p->s3[1] + k) >= p[0].min_f || (p->s3[0] + n) >= p[0].min_f)
		return (0);
	else if ((p->s4[1] + k) >= p[0].min_f || (p->s4[0] + n) >= p[0].min_f)
		return (0);
	if ((map[p->s1[1] + k][p->s1[0] + n]) != '.')
		return (0);
	else if ((map[p->s2[1] + k][p->s2[0] + n]) != '.')
		return (0);
	else if ((map[p->s3[1] + k][p->s3[0] + n]) != '.')
		return (0);
	else if ((map[p->s4[1] + k][p->s4[0] + n]) != '.')
		return (0);
	return (1);
}

int		fill_map(char **map, t_fill_cords *p, int k)
{
	int i;
	int j;
	int l;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j] && k < p->elem_static)
			if (p[k].use == 0 && valid_place(map, i, j, &p[k]) != 0
				&& k < p->elem_static)
			{
				write_fig(map, i, j, &p[k]);
				if (fill_map(map, p, ++k) == 1)
					return (1);
				else
					del_fig(map, i, j, &p[--k]);
			}
	}
	l = -1;
	while (++l < p->elem_static)
		if (p[l].use == 0)
			return (-1);
	return (1);
}
