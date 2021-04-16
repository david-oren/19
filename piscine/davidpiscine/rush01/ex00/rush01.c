/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 09:06:03 by ctirions          #+#    #+#             */
/*   Updated: 2020/09/20 17:35:25 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char		g_tab[4][4];
int			recurse(int *ptr, char argv[31]);
int			possible(int x, int y, char n);
int			ft_check(char argv[31]);

void		replace_nbr(int *ptr, char argv[31], int x, int y)
{
	char n;

	n = '0';
	while (++n < '5')
		if (possible(x, y, n))
		{
			g_tab[y][x] = n;
			recurse(ptr, argv);
			g_tab[y][x] = '0';
		}
}

void		printtab(void)
{
	int y;
	int x;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 3)
		{
			write(1, &g_tab[y][x], 1);
			write(1, " ", 1);
		}
		write(1, &g_tab[y][3], 1);
		write(1, "\n", 1);
	}
}

int			possible(int x, int y, char n)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (g_tab[y][i] == n)
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (g_tab[i][x] == n)
			return (0);
		i++;
	}
	return (1);
}

int			recurse(int *ptr, char argv[31])
{
	int		x;
	int		y;

	if (*ptr)
		return (1);
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			if (g_tab[y][x] == '0')
			{
				replace_nbr(ptr, argv, x, y);
				return (*ptr);
			}
	}
	if (ft_check(argv))
	{
		*ptr = 1;
		printtab();
	}
	return (*ptr);
}
