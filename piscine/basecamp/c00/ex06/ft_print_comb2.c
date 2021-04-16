/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:57:13 by daoren            #+#    #+#             */
/*   Updated: 2021/02/08 12:18:13 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	nb1;
	int nb2;

	nb1 = 0;
	nb2 = 1;
	while (nb1 < 99)
	{
		ft_putchar(nb1 / 10 + '0');
		ft_putchar(nb1 % 10 + '0');
		ft_putchar(' ');
		ft_putchar(nb2 / 10 + '0');
		ft_putchar(nb2 % 10 + '0');
		nb2++;
		if (nb1 != 98)
			write(1, ", ", 2);
		if (nb2 > 99)
		{
			nb1++;
			nb2 = nb1 + 1;
		}
	}
}

int		main(void)
{
	ft_print_comb2();
	return (0);
}
