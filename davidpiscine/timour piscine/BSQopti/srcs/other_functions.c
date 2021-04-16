/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 09:59:52 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/30 11:49:59 by tpetit           ###   ########.fr       */
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

void	change_max(t_fill_up_grid *loc, int value, int index)
{
	loc->max = value;
	loc->index_of_max = index;
}

int		get_min(int *last_line, int *curr_line, int index)
{
	const int nb1 = curr_line[index - 1];
	const int nb2 = last_line[index];
	const int nb3 = last_line[index - 1];

	if (nb1 <= nb2 && nb1 <= nb3)
		return (nb1);
	else if (nb2 <= nb3 && nb2 <= nb1)
		return (nb2);
	else
		return (nb3);
}
