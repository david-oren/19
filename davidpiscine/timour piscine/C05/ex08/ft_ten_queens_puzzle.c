/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 22:09:40 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:00:59 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		abs(int nb)
{
	if (nb > 0)
		return (nb);
	return (-nb);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_grid(int *grid)
{
	int i;

	i = -1;
	while (++i < 10)
	{
		ft_putchar(grid[i] + '0');
	}
	ft_putchar('\n');
}

int		check_poss(int *grid, int line)
{
	int i[2];
	int value;
	int q;
	int c;

	i[0] = grid[line];
	while (++i[0] < 10)
	{
		i[1] = -1;
		value = 1;
		q = line * 10 + i[0];
		while (++i[1] < line && grid[i[1]] != -1)
		{
			c = i[1] * 10 + grid[i[1]];
			if (q % 10 == grid[i[1]])
				value = 0;
			if (!(abs(q - c) % (11)) && abs(q - c) > abs(line - i[1]) * 10)
				value = 0;
			if (!(abs(q - c) % (9)) && abs(q - c) < abs(line - i[1]) * 10)
				value = 0;
		}
		if (value)
			return (i[0]);
	}
	return (-1);
}

int		ft_ten_queens_puzzle(void)
{
	int	grid[10];
	int count;
	int tot;
	int i;

	i = -1;
	tot = 0;
	while (++i < 10)
		grid[i] = -1;
	grid[0] = 0;
	count = 1;
	while (grid[0] != -1)
	{
		grid[count] = check_poss(grid, count);
		if (grid[count] == -1)
			count--;
		else
			count++;
		if (count == 10 && ++tot)
		{
			ft_print_grid(grid);
			count--;
		}
	}
	return (tot);
}

int main(void)
{
	ft_ten_queens_puzzle();
	return (0);
}
