/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01header.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 19:10:08 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:10:11 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01HEADER_H
# define RUSH01HEADER_H

int		respect_borders(int *grid, int *borders);
int		can_put_nbr(int index, int nbr);
void	put_nbr_in_grid(int index, int nbr);
void	print_solution(void);
int		search(int index, int *borders);

#endif
