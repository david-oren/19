/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:11:16 by daoren            #+#    #+#             */
/*   Updated: 2021/02/24 20:24:34 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int i;
	int j;

	j = nb;
	i = 1;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (j * ft_recursive_power(j, (power - 1)));
}

#include <stdio.h>

int main(void)
{
	printf("%d\n", ft_recursive_power(6, 2));
}
