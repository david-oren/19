/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 03:49:47 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/26 16:47:00 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
		write_numbers("numbers.dict", argv[1]);
	else if (argc == 3)
		write_numbers(argv[1], argv[2]);
	else
		ft_putstr("The number of arguments is not valid\n");
	return (0);
}
