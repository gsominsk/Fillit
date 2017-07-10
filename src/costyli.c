/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costyli.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 16:48:24 by gsominsk          #+#    #+#             */
/*   Updated: 2016/12/18 16:48:26 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

short	check_some_figure(t_fill_cords *p, int i)
{
	if ((p[i].s1[0] - p[i].s2[0] == -1) &&
		((p[i].s2[0] - p[i].s3[0] == 2) &&
		((p[i].s3[0] - p[i].s4[0] == -1))))
		return (1);
	if ((p[i].s1[0] - p[i].s2[0] == -1) &&
		((p[i].s2[0] - p[i].s3[0] == -1) &&
		((p[i].s3[0] - p[i].s4[0] == 2))))
		return (1);
	if ((p[i].s1[0] - p[i].s2[0] == 2) &&
		((p[i].s2[0] - p[i].s3[0] == -1) &&
		((p[i].s3[0] - p[i].s4[0] == -1))))
		return (1);
	return (0);
}

void	change(int *row, int *col_elem, int *str_len, int *elem)
{
	*row = 0;
	*col_elem = 0;
	*str_len += 1;
	*elem += 1;
}

int		add(int *col, int *row, int *str_len)
{
	if (*col != 4)
		return (0);
	*row += 1;
	*col = 0;
	*str_len += 1;
	return (1);
}

short	validate_near(t_fill_cords *p, int i)
{
	int k;

	k = 0;
	if (p[i].s1[1] - p[i].s2[1] == 0 || p[i].s1[0] - p[i].s2[0] == 0)
		k++;
	if (p[i].s1[1] - p[i].s3[1] == 0 || p[i].s1[0] - p[i].s3[0] == 0)
		k++;
	if (p[i].s1[1] - p[i].s4[1] == 0 || p[i].s1[0] - p[i].s4[0] == 0)
		k++;
	if (p[i].s2[1] - p[i].s3[1] == 0 || p[i].s2[0] - p[i].s3[0] == 0)
		k++;
	if (p[i].s2[1] - p[i].s4[1] == 0 || p[i].s2[0] - p[i].s4[0] == 0)
		k++;
	if (p[i].s3[1] - p[i].s4[1] == 0 || p[i].s3[0] - p[i].s4[0] == 0)
		k++;
	if (k < 3)
		return (0);
	return (1);
}
