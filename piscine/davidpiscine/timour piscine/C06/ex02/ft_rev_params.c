/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:01:11 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:01:18 by tpetit           ###   ########.fr       */
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

	i = -1;
	while (++i < argc - 1)
		ft_print_params(argv[argc - i - 1]);
	return (0);
}
