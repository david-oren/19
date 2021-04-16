/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:33:43 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/30 12:00:25 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

t_vec2u			c_vec2u(unsigned int x, unsigned int y)
{
	t_vec2u r;

	r.x = x;
	r.y = y;
	return (r);
}

t_fill_up_grid	c_fill_up_grid(void)
{
	t_fill_up_grid loc;

	loc.index = 0;
	loc.error = 0;
	loc.i = -1;
	loc.index_of_max = 0;
	loc.max = 0;
	loc.first = 1;
	return (loc);
}
