/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:59:25 by daoren            #+#    #+#             */
/*   Updated: 2021/02/10 21:22:20 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int swap1;
	int swap2;

	swap1 = *a;
	swap2 = *b;
	*a = swap1 / swap2;
	*b = swap1 % swap2;
}

int	main(void)
{
	int a;
	int b;
	
	a = 5;
	b = 2;
	ft_ultimate_div_mod(&a, &b);
	printf("div %d, left %d", a, b);
}
