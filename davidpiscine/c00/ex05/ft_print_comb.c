/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doren <doren@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:44:30 by doren             #+#    #+#             */
/*   Updated: 2020/09/26 21:04:37 by doren            ###   ########.fr       */
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

	nb1 = '0' - 1;
	while (++nb1 <= '9')
	{
		nb2 = nb1;
		while (++nb2 <= '9')
		{
			nb3 = nb2;
			while (++nb3 <= '9')
			{
				ft_putchar(nb1);
				ft_putchar(nb2);
				ft_putchar(nb3);
				if (nb1 != '7')
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
		}
	}
}
