/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:35:42 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:07:57 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(unsigned int nbr)
{
	if (nbr)
	{
		ft_print(nbr / 10);
		ft_putchar('0' + nbr % 10);
	}
}

void	ft_putnbr(int nb)
{
	unsigned int	newnb;

	if (nb == 0)
		ft_putchar('0');
	if (nb < 0)
	{
		newnb = -nb;
		write(1, "-", 1);
	}
	else
		newnb = nb;
	ft_print(newnb);
}
