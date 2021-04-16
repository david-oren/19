/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 11:55:58 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/29 18:01:40 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int			test_base(char c, char *base)
{
	int i;

	i = -1;
	while (base[++i])
	{
		if (base[i] == c)
			return (0);
	}
	return (1);
}

int			check_inbase(char *base, char c)
{
	int i;

	i = -1;
	while (base[++i])
		if (base[i] == c)
			return (1);
	return (0);
}

int			test_error(char *base, int *baselen)
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
	i = -1;
	while (base[++i])
		;
	*baselen = 0;
	*baselen = i;
	return (0);
}

int			calculate_to_add(char *base, int baselen, char c, int puiss)
{
	int index;
	int i;
	int value;

	i = -1;
	while (base[++i])
	{
		if (base[i] == c)
		{
			index = i;
			break ;
		}
	}
	i = -1;
	value = 1;
	while (++i < puiss)
	{
		value *= baselen;
	}
	return (value * index);
}

int			ft_atoi_base(char *str, char *base)
{
	int	num;
	int	neg;
	int baselen;
	int max;

	neg = 0;
	num = 0;
	max = 0;
	test_error(base, &baselen);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		neg = (*str == '-') ? !neg : neg;
		str++;
	}
	while (check_inbase(base, str[++max]))
		;
	while (check_inbase(base, *str))
	{
		num += calculate_to_add(base, baselen, *str, max - 1);
		str++;
		max--;
	}
	return (neg ? -num : num);
}
