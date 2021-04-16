/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:54:29 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/29 19:40:49 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_atoi_base(char *str, char *base);
int				is_valid(const char *base);
unsigned int	base_len(char *base);
unsigned int	g_count = 0;

unsigned int	next_nb_len(int nb, char *base_to)
{
	unsigned int r;
	unsigned int unb;

	if (nb == 0)
		return (1);
	r = 0;
	unb = nb;
	if (nb < 0)
	{
		unb = -nb;
		r++;
	}
	while (unb)
	{
		unb /= base_len(base_to);
		r++;
	}
	return (r);
}

char			*ft_putnbr_base(unsigned int unum, char *base_to, char *num)
{
	if (unum < base_len(base_to))
	{
		num[g_count] = base_to[unum];
		g_count++;
	}
	else
	{
		ft_putnbr_base(unum / base_len(base_to), base_to, num);
		num[g_count] = base_to[unum % base_len(base_to)];
		g_count++;
	}
	return (num);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int				nb;
	char			*num;
	unsigned int	unum;
	int				next_base_nb_len;

	g_count = 0;
	if (!is_valid(base_from) || !is_valid(base_to))
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	next_base_nb_len = next_nb_len(nb, base_to);
	if (!(num = malloc(next_base_nb_len + 1)))
		return (0);
	num[next_base_nb_len] = 0;
	unum = nb;
	if (nb < 0)
	{
		unum = -nb;
		num[0] = '-';
		g_count++;
	}
	return (ft_putnbr_base(unum, base_to, num));
}
