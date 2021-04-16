/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkalinic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 12:03:44 by kkalinic          #+#    #+#             */
/*   Updated: 2020/09/26 13:37:35 by kkalinic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_check_num(char *a)
{
	int i;

	i = -1;
	while(a[++i] != '\0')
	{
		if (!(a[i] >= 48 && a[i] <= 57))
				return (1);
	}
	return (0);
}

int	ft_filter(int argc, char **argv)
{
	if (argc != 3 && argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}	

	if (argc == 2)
	{
		if (1 == ft_check_num(argv[1]))
		{
			write(1, "Error\n", 6);
			return (1);
		}
	}
	if (argc == 3)
	{
		if (1 == ft_check_num(argv[2]))
		{
				write(1, "Error\n", 6);
				return (1);
		}
	}
	return (0);

}


