/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 16:50:20 by gsominsk          #+#    #+#             */
/*   Updated: 2016/12/18 16:50:21 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

short	validate_fig(t_fill_cords *p, int i)
{
	if (((p[i].s1[1] - p[i].s2[1] != -1) &&
		(p[i].s1[1] - p[i].s2[1] != 0) &&
		(p[i].s1[1] - p[i].s2[1] != 1)) ||
		((p[i].s2[1] - p[i].s3[1] != -1) &&
		(p[i].s2[1] - p[i].s3[1] != 0) &&
		(p[i].s2[1] - p[i].s3[1] != 1)) ||
		((p[i].s3[1] - p[i].s4[1] != -1) &&
		(p[i].s3[1] - p[i].s4[1] != 0) &&
		(p[i].s3[1] - p[i].s4[1] != 1)))
		return (0);
	if (((p[i].s1[0] - p[i].s2[0] != -1) &&
		(p[i].s1[0] - p[i].s2[0] != 0) &&
		(p[i].s1[0] - p[i].s2[0] != 1)) ||
		((p[i].s2[0] - p[i].s3[0] != -1) &&
		(p[i].s2[0] - p[i].s3[0] != 0) &&
		(p[i].s2[0] - p[i].s3[0] != 1)) ||
		((p[i].s3[0] - p[i].s4[0] != -1) &&
		(p[i].s3[0] - p[i].s4[0] != 0) &&
		(p[i].s3[0] - p[i].s4[0] != 1)))
		return (0);
	if (validate_near(p, i) == 0)
		return (0);
	return (1);
}

short	validate_fig_ang(t_fill_cords *p, int elem, char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (!(str[i] == '.' || str[i] == '#' || str[i] == '\n'
			|| str[i] == '\0'))
			return (0);
	i = -1;
	while (++i < elem)
	{
		if (check_some_figure(p, i) == 1)
			i++;
		else
		{
			if (validate_fig(p, i) == 0)
				return (0);
			if ((p[i].s1[0] - p[i].s2[0]) == (p[i].s1[1] - p[i].s2[1]) ||
			(p[i].s3[0] - p[i].s4[0]) == (p[i].s3[1] - p[i].s4[1]))
				return (0);
		}
	}
	show_map(create_map(elem, p, str));
	return (1);
}

short	validate_elem(char *str)
{
	int str_len;
	int col_elem;

	str_len = -1;
	col_elem = 0;
	while (str[++str_len])
	{
		if (str[str_len] == '#')
			col_elem++;
		if (str[str_len] == '\n' && (str[str_len + 1] == '\n' ||
			str[str_len + 1] == '\0'))
		{
			if (col_elem != 4)
				return (0);
			col_elem = 0;
		}
	}
	return (1);
}

short	validate_block(char *str)
{
	int	str_len;
	int row;
	int col;

	str_len = -1;
	col = 0;
	row = 0;
	while (str[++str_len])
	{
		if (str[str_len] == '\n')
			if (add(&col, &row, &str_len) == 0)
				return (0);
		if (str[str_len] == '\n' && str[str_len - 1] == '\n')
		{
			if (row != 4)
				return (0);
			row = 0;
			str_len++;
		}
		col++;
		if (row > 4 || col > 4)
			return (0);
	}
	return (1);
}

short	validate_file(char *str, int num_elem)
{
	if (ft_strlen(str) != (size_t)(num_elem * 20 + num_elem - 1))
		return (0);
	if (validate_block(str) == 0)
		return (0);
	if (validate_elem(str) == 0)
		return (0);
	return (1);
}
