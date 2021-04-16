/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 22:19:27 by daoren            #+#    #+#             */
/*   Updated: 2021/02/07 18:23:52 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	char nb1;
	char nb2;
	char nb3;

	nb1 = '0';
	while (nb1 <= '9')
	{
		nb2 = nb1 + 1;
		while (nb2 <= '9')
		{
			nb3 = nb2 + 1;
			while (nb3 <= '9')
			{
				ft_putchar(nb1);
				ft_putchar(nb2);
				ft_putchar(nb3);
				if (nb1 != '7' || nb2 != '8' || nb3 != '9')
					write(1, ", ", 2);
				nb3++;
			}
			nb2++;
		}
		nb1++;
	}
}

int		main(void)
{
	ft_print_comb();
	return (0);
}
