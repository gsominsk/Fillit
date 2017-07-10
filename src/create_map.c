/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 16:48:39 by gsominsk          #+#    #+#             */
/*   Updated: 2016/12/18 16:48:40 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			min_field(int elem, t_fill_cords *p)
{
	int min_field;
	int n;
	int i;

	min_field = elem * 4;
	n = 1;
	while (min_field > (n * n))
		n++;
	i = -1;
	while (++i < elem)
		p[i].min_f = n;
	return (n);
}

void		obnulit(int elem, t_fill_cords *coord)
{
	int i;

	i = -1;
	while (++i < elem)
		coord[i].use = 0;
}

static char	**fill_map_dot(char **map, int min_f)
{
	int i;
	int j;

	i = -1;
	while (++i < min_f)
	{
		j = -1;
		if ((map[i] = (char *)malloc(sizeof(char) * (min_f + 1))) == NULL)
			return (NULL);
		while (++j < min_f)
			map[i][j] = '.';
		map[i][j] = '\0';
	}
	return (map);
}

char		**create_map(int elem, t_fill_cords *coord, char *str)
{
	int		min_f;
	char	**map;
	int		i;
	int		k;

	obnulit(elem, coord);
	min_f = min_field(elem, coord);
	if ((map = (char **)malloc(sizeof(char *) * (min_f + 2))) == NULL)
		return (NULL);
	map[min_f + 1] = NULL;
	i = -1;
	while (++i < elem)
		coord[i].elem_static = ft_num_el(str);
	map = fill_map_dot(map, min_f);
	k = 0;
	if (fill_map(map, coord, k) == -1)
		map = create_map(elem + 1, coord, str);
	return (map);
}
