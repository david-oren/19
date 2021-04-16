/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:11:23 by daoren            #+#    #+#             */
/*   Updated: 2021/02/22 16:59:48 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int i;

	i = 1;
	if (nb <= 1)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	while (++i <= nb / 5)
	{
		if (nb % i == 0)
			return (0);
	}
	return (1);
}

#include <stdio.h>
int main()
{
	printf("%d\n", ft_is_prime(-1));
	return (0);
}
