/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 16:49:26 by gsominsk          #+#    #+#             */
/*   Updated: 2016/12/18 16:49:27 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define ROW 600

int		main(int argc, char const *argv[])
{
	char			s[ROW];
	t_fill_cords	*cd;
	int				elem;

	if (argc == 2)
	{
		if ((ft_find_file((char *)argv[1], s) == NULL)
			|| (validate_file(s, ft_num_el(s))) == 0)
		{
			if (func_error() == 0)
				return (0);
		}
		else
		{
			cd = (t_fill_cords *)malloc(sizeof(t_fill_cords) * (ft_num_el(s)));
			elem = ft_find_elem(s, cd);
			if ((validate_fig_ang(cd, elem, s)) == 0)
				if (func_error() == 0)
					return (0);
		}
	}
	else
		ft_putstr("usage: ./fillit <path>\n");
	return (0);
}
