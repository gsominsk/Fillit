/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emasiuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:47:21 by emasiuk           #+#    #+#             */
/*   Updated: 2016/12/18 17:47:26 by emasiuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*str;

	i = 0;
	if (s == '\0')
		return (0);
	if ((str = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	while (i < len)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = -1;
	while (str[++i] != '\0')
		;
	return (i);
}

void	ft_putstr(char *s)
{
	if (s == '\0')
		return ;
	while (*s != '\0')
	{
		ft_putchar(*s);
		s++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
