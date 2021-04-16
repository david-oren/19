/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engonzal <engonzal@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:07:19 by daoren            #+#    #+#             */
/*   Updated: 2021/02/21 20:53:50 by engonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "lib.h"

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	write(1, "JOYEUX ANNIF CORENTIN J+1", 30);
	return (0);
}
