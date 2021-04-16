/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 15:04:09 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:13:04 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
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
	write(1, "\n", 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = -1;
	while (par[++i]->str)
	{
		ft_putstr(par[i]->str);
		ft_putnbr(par[i]->size);
		ft_putstr(par[i]->copy);
	}
}
