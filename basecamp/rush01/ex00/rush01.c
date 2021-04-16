/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:42:20 by daoren            #+#    #+#             */
/*   Updated: 2021/02/22 13:22:48 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_tab[4][4];

backtracking = 

int		solution(int *ptr)  la fct solution devait implementer la reucrsive afin de rendre le backtracking operationel
{
	int i;
	int j;

	if (*ptr)
		return (1);
	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
			if (g_tab[j][i] == '0')
			{			bien compris le principe mais pas reussi a le faire
			}
	}
	return (*ptr);
}

void	printtab(void)
{
	int j;
	int i;

	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
		{
			write(1, &g_tab[j][i], 1);   permet l espace entre les input
			write(1, " ", 1);
		}
		write(1, &g_tab[j][3], 1); pour faire un passage as la ligne entre les lignes du tableau
		write(1, "\n", 1);
	}
}
