/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 07:44:55 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:07:51 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int val1;
	int val2;

	i = -1;
	val1 = 1;
	val2 = 1;
	if (length <= 1)
		return (1);
	while (++i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			val1 = 0;
		if (f(tab[i], tab[i + 1]) < 0)
			val2 = 0;
	}
	return (val1 || val2);
}
