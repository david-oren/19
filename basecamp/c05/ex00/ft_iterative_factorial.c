/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:11:05 by daoren            #+#    #+#             */
/*   Updated: 2021/02/22 11:49:42 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int i;
	int j;

	i = 1;
	j = 1;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	while (i <= nb)
	{
		j = j * i;
		i++;
	}
	return (j);
}

#include <stdio.h>

int		main(void)
{
	printf("%d\n", ft_iterative_factorial(9));
}
