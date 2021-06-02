/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:06:20 by daoren            #+#    #+#             */
/*   Updated: 2021/06/02 18:17:19 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_power_of_10(int nb, int power)
{
	while (--power > 0)
		nb = nb * 10;
	return (nb);
}

int	ft_atoi(const char *str)
{
	int					sign;
	int					i;
	unsigned long long	return_nb;

	sign = 1;
	i = 0;
	return_nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		str++;
	if (str[i] == ' ' || str[i] == '-' || str[i] == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if ((i >= 19 || return_nb > (1ull << 63) - 1 && sign > 0)
		return (-1);
	else if ((i >= 19 || return_nb > 1ull << 63) && sign < 0)
		return (0);
	while (i > 0)
		return_nb += ft_power_of_10(*(str++) - '0', i--);
	return (return_nb * sign);
}

