/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:30:30 by daoren            #+#    #+#             */
/*   Updated: 2021/04/02 15:47:41 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	unsigned int	i;

	i = 0;
	if (!(n))
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long			i;
	unsigned long	nb;
	char			*str;
	int				neg;

	nb = n;
	neg = 0;
	if (n < 0)
	{
		nb *= -1;
		neg = 1;
	}
	i = ft_count(n);
	str = (char *) malloc(sizeof(char) * (ft_count(n) + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (n < 0)
		str[0] = '-';
	while (i-- > neg)
	{
		str[i] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
