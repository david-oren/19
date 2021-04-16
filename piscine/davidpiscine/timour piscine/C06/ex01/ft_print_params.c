/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:55:41 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:01:16 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_params(char *parname)
{
	int i;

	i = -1;
	while (parname[++i])
	{
		write(1, &parname[i], 1);
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	while (++i < argc)
		ft_print_params(argv[i]);
	return (0);
}
