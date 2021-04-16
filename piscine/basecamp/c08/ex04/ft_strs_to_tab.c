/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 21:40:24 by daoren            #+#    #+#             */
/*   Updated: 2021/02/25 10:31:32 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int		ft_strlen(char *str)
{
	int a;

	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dest;

	dest = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strcpy(dest, src);
	return (dest);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int 		i;
	t_stock_str *tab;

	i = 0;
	if (ac < 0)
		ac = 0;
	tab = malloc(sizeof(t_stock_str) * (ac + 1));
	if (tab == NULL)
		return (NULL);
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		i++;
	}
	tab[i].str = 0;
	return (tab);
}

#include <stdio.h>

int        main(void)
{
    char *av[] = {"hello",
                "ca va",
                "ok"};
    int ac = 3;
    t_stock_str    *stock_str;
    stock_str = ft_strs_to_tab(ac, av);
    printf("%d\n", stock_str[0].size);
    printf("%s\n", stock_str[0].str);
    printf("%s\n", stock_str[0].copy);
    printf("%d\n", stock_str[1].size);
    printf("%s\n", stock_str[1].str);
    printf("%s\n", stock_str[1].copy);
    printf("%d\n", stock_str[2].size);
    printf("%s\n", stock_str[2].str);
    printf("%s\n", stock_str[2].copy);
    return (0);
}
