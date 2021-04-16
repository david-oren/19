/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 19:09:52 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:09:54 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush01header.h"

void	to_int_array(char *argv, int *borders)
{
	int i;

	i = -1;
	while (++i < 16)
		borders[i] = argv[i * 2] - '0';
}

int		str_len(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		;
	return (i);
}

int		iscorrectargument(char *argv)
{
	int i;

	if (str_len(argv) != 31)
		return (0);
	i = -1;
	while (++i < 31)
	{
		if (i % 2 == 1 && argv[i] != ' ')
			return (0);
		if (i % 2 == 0 && !(argv[i] >= '1' && argv[i] <= '4'))
			return (0);
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	int borders[16];

	if (argc != 2 || !iscorrectargument(argv[1]))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	to_int_array(argv[1], borders);
	if (!search(0, borders))
		write(1, "Error\n", 6);
	return (0);
}
