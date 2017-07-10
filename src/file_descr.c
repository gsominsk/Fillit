/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_descr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsominsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 16:49:00 by gsominsk          #+#    #+#             */
/*   Updated: 2016/12/18 16:49:01 by gsominsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_find_file(char *file_name, char *str)
{
	char	*str_buff;
	size_t	fp_1;
	size_t	fp_2;

	fp_1 = open(file_name, O_RDONLY);
	if (fp_1 == (size_t)-1)
		return (NULL);
	if ((fp_2 = read(fp_1, str, 1000)) == (size_t)-1)
		return (NULL);
	str_buff = ft_strsub(str, 0, ft_strlen(str));
	fp_1 = ft_strlen(str_buff);
	return (str_buff);
}
