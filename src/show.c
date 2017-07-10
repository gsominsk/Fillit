/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 16:49:38 by gsominsk          #+#    #+#             */
/*   Updated: 2016/12/18 16:49:39 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	show_map(char **map)
{
	size_t	i;

	i = -1;
	while (map[++i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
	}
}

int		func_error(void)
{
	ft_putstr("error\n");
	return (0);
}
