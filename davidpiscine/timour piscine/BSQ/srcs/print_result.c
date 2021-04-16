/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:17:52 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/30 16:34:35 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void	print_while(int *grid, t_grid_prop grid_info,
		t_vec2u pos, t_vec2u posind)
{
	char			*toprint;

	if (!(toprint = malloc(sizeof(char) * grid_info.width)))
		return (ft_puterr("malloc error\n"));
	while (++pos.y < grid_info.height)
	{
		pos.x = -1;
		while (++pos.x < grid_info.width)
		{
			if (grid[pos.y * grid_info.width + pos.x] == 0)
				toprint[pos.x] = grid_info.notempty;
			else if (pos.x >= posind.x - pos.ind + 1 && pos.x <= posind.x
				&& pos.y >= posind.y - pos.ind + 1 && pos.y <= posind.y)
				toprint[pos.x] = grid_info.square;
			else
				toprint[pos.x] = grid_info.empty;
		}
		write(1, toprint, grid_info.width);
		ft_putstr("\n");
	}
	free(toprint);
}

void	print_result(int *grid, t_grid_prop grid_info, int index)
{
	t_vec2u			pos;
	t_vec2u			posind;

	pos = c_vec2u(-1, -1, grid[index]);
	posind = c_vec2u(index % grid_info.width, index / grid_info.width, 0);
	print_while(grid, grid_info, pos, posind);
	free(grid);
}
