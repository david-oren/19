/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:11:21 by daoren            #+#    #+#             */
/*   Updated: 2021/02/22 15:59:40 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_autrement(int nb, int sqrt, int stop)
{
	if (sqrt * sqrt == nb)
		return (sqrt);
	else if (sqrt * sqrt < nb && sqrt <= 46340)
		return (ft_autrement(nb, sqrt + 1, stop));
	return (0);
}

int	ft_sqrt(int nb)
{
	int sqrt;

	sqrt = 1;
	return (ft_autrement(nb, sqrt, nb / 2));
}

#include <stdio.h>
int main()
{
	printf("%d\n", ft_sqrt(2147483647));
	return (0);
}
