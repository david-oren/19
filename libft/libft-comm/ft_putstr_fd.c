/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:30:45 by daoren            #+#    #+#             */
/*   Updated: 2021/04/12 20:51:19 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Tout comme un put_str sauf qu'on écrit la sortie dans le fichier fd, on écrit le s avec comme longueur de chaine le résultat de la fonction ft_strlen(s)


void	ft_putstr_fd(char *s, int fd)
{
	if (s && fd >= 0)		// protection si le fichier file descriptor n est pas une erreur
		write(fd, s, ft_strlen(s));
}

