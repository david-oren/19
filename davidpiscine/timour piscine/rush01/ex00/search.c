/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 19:10:17 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:10:19 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush01header.h"

int	g_foundsmth = 0;
int	g_grid[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int		search(int index, int *borders)
{
	int nbr;

	nbr = 1;
	if (index == 16)
	{
		if (respect_borders(g_grid, borders))
		{
			print_solution();
			g_foundsmth = 1;
		}
		return (g_foundsmth);
	}
	while (nbr <= 4)
	{
		if (can_put_nbr(index, nbr))
		{
			put_nbr_in_grid(index, nbr);
			search(index + 1, borders);
			if (g_foundsmth)
				return (g_foundsmth);
			put_nbr_in_grid(index, 0);
		}
		nbr++;
	}
	return (g_foundsmth);
}

int		can_put_nbr(int index, int nbr)
{
	int x;
	int y;
	int i;

	x = index % 4;
	y = index / 4;
	i = -1;
	while (++i < 4)
	{
		if (g_grid[y * 4 + i] == nbr)
			return (0);
		if (g_grid[i * 4 + x] == nbr)
			return (0);
	}
	return (1);
}

void	put_nbr_in_grid(int index, int nbr)
{
	g_grid[index] = nbr;
}

void	print_solution(void)
{
	int		x;
	int		y;
	char	c;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			c = '0' + g_grid[y * 4 + x];
			write(1, &c, 1);
		}
		write(1, "\n", 1);
	}
}
