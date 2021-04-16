/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:30:36 by daoren            #+#    #+#             */
/*   Updated: 2021/04/12 20:47:26 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// On va écrire la desitnation dans un autre fichier

void	ft_putchar_fd(char c, int fd)		
{
	if (fd >= 0)				// protection si le fichier file descriptor n est pas une erreur
		write(fd, &c, 1);		// On écrit fd à la place de 1, 1 correspondait à la sortie standard alors qu'avec fd on va écrire le write dans un fichier distant. 
					// Comme pendant la piscine le & correspond à l'adress de de C
					// Le dernier 1 = le nombre de char
}
