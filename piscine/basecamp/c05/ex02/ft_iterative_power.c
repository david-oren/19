/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:11:13 by daoren            #+#    #+#             */
/*   Updated: 2021/02/22 11:53:10 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int i;
	int j;

	i = 1;
	j = 1;
	if (power < 0)
		return (0);
	while (i <= power)
	{
		if (power == 0)
			return (1);
		else
		{
			j = j * nb;
			i++;
		}
	}
	return (j);
}

#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_iterative_power(8, 2));
}
