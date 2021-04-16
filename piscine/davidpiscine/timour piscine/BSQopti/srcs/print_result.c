/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:17:52 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/30 12:29:41 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

void	print_result(char *grid, t_grid_prop grid_info, t_fill_up_grid index)
{
	t_vec2u			pos;
	t_vec2u			posind;

	pos = c_vec2u(-1, -1);
	posind = c_vec2u(index.index_of_max % (grid_info.width + 1), index.index_of_max / (grid_info.width + 1));
	while (++pos.y < grid_info.height)
	{
		pos.x = -1;
		while (++pos.x < grid_info.width)
		{
			if (pos.x >= posind.x - index.max + 1 && pos.x <= posind.x && pos.y >= posind.y - index.max + 1 && pos.y <= posind.y)
				grid[pos.y * (grid_info.width + 1) + pos.x] = grid_info.square;
		}
	}
	write(1, grid, (grid_info.width + 1) * grid_info.height);
}
