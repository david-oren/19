/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:30:38 by daoren            #+#    #+#             */
/*   Updated: 2021/04/12 20:46:36 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// On ajoute la chaine de character s dans un fichier fd puis on ajoute un \n à la fin

void	ft_putendl_fd(char *s, int fd)		
{
	if (fd < 0)				// protection si le fichier file descriptor n est pas une erreur
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
