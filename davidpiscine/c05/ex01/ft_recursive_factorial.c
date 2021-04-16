/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doren <doren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:57:02 by doren             #+#    #+#             */
/*   Updated: 2020/09/26 15:04:30 by doren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb == 1)
		return (nb);
	if (nb == 0)
		return (1);
	else if (nb < 0)
	{
		return (0);
	}
	else
		return (nb * ft_recursive_factorial(nb - 1));
}
