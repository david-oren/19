/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 20:11:07 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/30 13:17:08 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_valid(const char *base)
{
	int i;
	int j;

	i = -1;
	j = 0;
	if (!base[0] || !base[1])
		return (0);
	while (base[++i])
	{
		while (base[j])
		{
			if (i != j && base[i] == base[j])
				return (0);
			j++;
		}
		j = 0;
	}
	while (*base)
	{
		if (*base == '+' || *base == '-' || *base == ' ' || *base == '\t'
			|| *base == '\n' || *base == '\v' || *base == '\f' || *base == '\r')
			return (0);
		base++;
	}
	return (1);
}

int		is_in_base(char c, char *base)
{
	while (*base)
	{
		if (c == *base)
			return (1);
		base++;
	}
	return (0);
}

int		base_len(char *base)
{
	int i;

	i = -1;
	while (base[++i])
		;
	return (i);
}

int		get_index(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	unsigned int	num;
	int				s;

	num = 0;
	s = 1;
	if (!is_valid(base))
		return (0);
	while (*str && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			s *= -1;
		str++;
	}
	while (*str && is_in_base(*str, base))
	{
		num = num * base_len(base) + get_index(*str, base);
		str++;
	}
	return (num * s);
}
