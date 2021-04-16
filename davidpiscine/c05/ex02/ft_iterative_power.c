/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doren <doren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 16:00:31 by doren             #+#    #+#             */
/*   Updated: 2020/09/25 19:00:04 by doren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int i;
	int j;

	j = 1;
	i = 1;
	if (power < 0)
	{
		return (0);
	}
	while (i <= power)
	{
		if (power == 0)
		{
			return (1);
		}
		else
		{
			j = j * nb;
			i++;
		}
	}
	return (j);
}
