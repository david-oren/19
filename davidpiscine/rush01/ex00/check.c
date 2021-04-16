/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 11:13:54 by ctirions          #+#    #+#             */
/*   Updated: 2020/09/20 17:56:51 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*create_input_tab(char argv[31]);
char	g_tab[4][4];

int		check_up(char up, int i)
{
	int		y;
	char	verif;
	char	maxheight;

	verif = '1';
	maxheight = g_tab[0][i];
	y = -1;
	while (++y < 4)
	{
		if (maxheight < g_tab[y][i])
		{
			verif++;
			maxheight = g_tab[y][i];
		}
	}
	if (verif == up)
		return (1);
	return (0);
}

int		check_down(char down, int i)
{
	int		y;
	char	verif;
	char	maxheight;

	i %= 4;
	verif = '1';
	maxheight = g_tab[3][i];
	y = 4;
	while (--y >= 0)
		if (maxheight < g_tab[y][i])
		{
			verif++;
			maxheight = g_tab[y][i];
		}
	if (verif == down)
		return (1);
	return (0);
}

int		check_left(char left, int i)
{
	int		x;
	char	verif;
	char	maxheight;

	i %= 4;
	verif = '1';
	maxheight = g_tab[i][0];
	x = -1;
	while (++x < 4)
		if (maxheight < g_tab[i][x])
		{
			verif++;
			maxheight = g_tab[i][x];
		}
	if (verif == left)
		return (1);
	return (0);
}

int		check_right(char right, int i)
{
	int		x;
	char	verif;
	char	maxheight;

	i %= 4;
	verif = '1';
	maxheight = g_tab[i][3];
	x = 4;
	while (--x >= 0)
		if (maxheight < g_tab[i][x])
		{
			verif++;
			maxheight = g_tab[i][x];
		}
	if (verif == right)
		return (1);
	return (0);
}

int		ft_check(char argv[31])
{
	int	i;
	int	verif;
	char *ptr;

	ptr = create_input_tab(argv);
	i = -1;
	verif = 0;
	while (++i < 4)
		verif += check_up(create_input_tab(argv)[i], i);
	i--;
	while (++i < 8)
		verif += check_down(create_input_tab(argv)[i], i);
	i--;
	while (++i < 12)
		verif += check_left(create_input_tab(argv)[i], i);
	i--;
	while (++i < 16)
		verif += check_right(create_input_tab(argv)[i], i);
	free(ptr);
	if (verif == 16)
		return (1);
	return (0);
}
