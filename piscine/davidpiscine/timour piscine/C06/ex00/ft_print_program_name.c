/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:02:53 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:01:15 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_program_name(char *name)
{
	int i;

	i = -1;
	while (name[++i])
	{
		write(1, &name[i], 1);
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	int i;

	i = argc;
	ft_print_program_name(argv[0]);
	return (0);
}
