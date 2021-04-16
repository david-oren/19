/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doren <doren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 10:19:47 by doren             #+#    #+#             */
/*   Updated: 2020/09/13 12:11:18 by doren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_line(int x, char c, char d, char e)
{
	int		i;

	i = 1;
	while (i <= x)
	{
		if (i == 1)
			ft_putchar(c);
		else if (i == x)
			ft_putchar(e);
		else
			ft_putchar(d);
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int		i;

	i = 1;
	if (x <= 0 || y <= 0)
		return ;
	if (i == 1)
	{
		print_line(x, 'A', 'B', 'C');
		i++;
	}
	while (i > 1 && i < y)
	{
		print_line(x, 'B', ' ', 'B');
		i++;
	}
	if (i == y)
	{
		print_line(x, 'C', 'B', 'A');
		i++;
	}
}
