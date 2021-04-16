/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 09:59:52 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/29 17:21:50 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int		test_char_in_grid(const t_grid_prop *grid)
{
	if (grid->empty == grid->notempty || grid->empty == grid->square
		|| grid->notempty == grid->square)
		return (0);
	if (grid->empty <= 31 || grid->notempty <= 31 || grid->square <= 31)
		return (0);
	return (1);
}

void	change_max(t_fill_up_grid *loc, int *grid)
{
	loc->max = grid[loc->index];
	loc->index_of_max = loc->index;
}

int		get_min(int *grid, const t_grid_prop *grid_info, int index)
{
	const int nb1 = grid[index - 1];
	const int nb2 = grid[index - grid_info->width];
	const int nb3 = grid[index - grid_info->width - 1];

	if (nb1 <= nb2 && nb1 <= nb3)
		return (nb1);
	else if (nb2 <= nb3 && nb2 <= nb1)
		return (nb2);
	else
		return (nb3);
}
