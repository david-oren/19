/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doren <doren@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:10:08 by doren             #+#    #+#             */
/*   Updated: 2020/09/26 21:04:08 by doren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int		a_copy;
	int		b_copy;

	a_copy = *a;
	b_copy = *b;
	*a = a_copy / b_copy;
	*b = a_copy % b_copy;
}
