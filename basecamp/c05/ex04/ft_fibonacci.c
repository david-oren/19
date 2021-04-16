/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:11:18 by daoren            #+#    #+#             */
/*   Updated: 2021/02/22 11:54:29 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else
		return ((ft_fibonacci(index - 1)) + (ft_fibonacci(index - 2)));
}

#include <stdio.h>

int main(void)
{
	printf("%d\n", ft_fibonacci(-1));
}
