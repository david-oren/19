/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 12:03:29 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:02:04 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
#include <stdio.h>

int					ft_strlen(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

char				*ft_strdup(char *str, int len)
{
	int		i;
	char	*dest;

	if (!(dest = malloc(len * sizeof(char))))
		return (NULL);
	i = -1;
	while (++i < len)
		dest[i] = str[i];
	dest[i] = 0;
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	t_stock_str			*t_stock;

	i = -1;
	if (ac < 0)
		ac = 0;
	if (!(t_stock = malloc(sizeof(t_stock_str) * (ac + 1))))
		return (NULL);
	while (++i < ac)
	{
		t_stock[i].size = ft_strlen(av[i]);
		t_stock[i].str = av[i];
		t_stock[i].copy = ft_strdup(av[i], ft_strlen(av[i]) + 1);
	}
	t_stock[i].str = 0;
	return (t_stock);
}
