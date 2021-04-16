/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   respect_borders.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 19:10:00 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:10:01 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01header.h"

int		rowl(int *grid, int *borders)
{
	int i;
	int j;
	int max;
	int count;

	i = 7;
	while (++i < 12)
	{
		j = -1;
		count = 1;
		max = grid[(i - 8) * 4];
		while (++j < 3)
		{
			if (grid[(i - 8) * 4 + j + 1] > max)
			{
				max = grid[(i - 8) * 4 + j + 1];
				count++;
			}
		}
		if (count != borders[i])
			return (0);
	}
	return (1);
}

int		rowr(int *grid, int *borders)
{
	int i;
	int j;
	int max;
	int count;

	i = 11;
	while (++i < 16)
	{
		j = -1;
		count = 1;
		max = grid[(i - 12) * 4 + 3];
		while (++j < 3)
		{
			if (grid[(i - 12) * 4 + 3 - 1 - j] > max)
			{
				max = grid[(i - 12) * 4 + 3 - 1 - j];
				count++;
			}
		}
		if (count != borders[i])
			return (0);
	}
	return (1);
}

int		colu(int *grid, int *borders)
{
	int i;
	int j;
	int max;
	int count;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		count = 1;
		max = grid[i];
		while (++j < 3)
		{
			if (grid[((j + 1) * 4) + i] > max)
			{
				max = grid[((j + 1) * 4) + i];
				count++;
			}
		}
		if (count != borders[i])
			return (0);
	}
	return (1);
}

int		cold(int *grid, int *borders)
{
	int i;
	int j;
	int max;
	int count;

	i = 3;
	while (++i < 8)
	{
		j = -1;
		count = 1;
		max = grid[8 + i];
		while (++j < 3)
		{
			if (grid[((2 - j) * 4) + (i - 4)] > max)
			{
				max = grid[((2 - j) * 4) + (i - 4)];
				count++;
			}
		}
		if (count != borders[i])
			return (0);
	}
	return (1);
}

int		respect_borders(int *grid, int *borders)
{
	if (rowl(grid, borders) && rowr(grid, borders) &&
	colu(grid, borders) && cold(grid, borders))
		return (1);
	return (0);
}
