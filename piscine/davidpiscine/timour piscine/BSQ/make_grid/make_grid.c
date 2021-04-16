/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 20:19:53 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/30 18:10:09 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "ft_lib.h"

void	make_grid(unsigned int h, unsigned int w, char *em_nem_square)
{
	unsigned int	i;
	unsigned int	j;
	char			*toprint;

	i = -1;
	toprint = malloc(sizeof(char) * w);
	ft_putnbr(h);
	write(1, &em_nem_square[0], 1);
	write(1, &em_nem_square[1], 1);
	write(1, &em_nem_square[2], 1);
	write(1, "\n", 1);
	while (++i < h)
	{
		j = -1;
		while (++j < w)
		{
			if (rand() % 10)
				toprint[j] = em_nem_square[0];
			else
				toprint[j] = em_nem_square[1];
		}
		write(1, toprint, w);
		write(1, "\n", 1);
	}
}

int		main(void)
{
	int		height;
	int		width;
	char	em_nem_square[3];

	srand(time(NULL));
	height = 100;
	width = 100;
	em_nem_square[0] = '.';
	em_nem_square[1] = '0';
	em_nem_square[2] = '#';
	make_grid(height, width, em_nem_square);
	return (0);
}
