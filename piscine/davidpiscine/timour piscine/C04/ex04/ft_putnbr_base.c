/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 10:03:15 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 18:59:52 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_baselen(char *base, int *count)
{
	int i;

	i = -1;
	while (base[++i])
		;
	*count = i;
}

int		test_error(char *base)
{
	int i;
	int j;

	i = -1;
	while (base[++i])
		if (base[i] == '-' || base[i] == '+')
			return (1);
	if (i <= 1)
		return (1);
	i = -1;
	while (base[++i])
	{
		j = i;
		while (base[j++])
		{
			if (base[j] == base[i] && i != j)
				return (1);
		}
	}
	return (0);
}

void	ft_print_base(char *base, int basecount, long nbr)
{
	if (nbr == 0)
		return ;
	else
	{
		ft_print_base(base, basecount, nbr / basecount);
		ft_putchar(base[nbr % basecount]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	num;
	int				basecount;

	if (test_error(base))
		return ;
	if (nbr == 0)
	{
		ft_putchar(base[0]);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		num = 0 - nbr;
	}
	else
		num = nbr;
	ft_baselen(base, &basecount);
	ft_print_base(base, basecount, num);
}
