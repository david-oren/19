/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:30:41 by daoren            #+#    #+#             */
/*   Updated: 2021/04/12 20:46:44 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Écrire n'importe quel chiffre dans un fichier fd

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (fd < 0)				// protection si le fichier file descriptor n est pas une erreur
		return ;
	if (n < 0)				// Si le nombre est négatif on utilise la fonction putchar pour print le signe -
	{
		nb = -n;
		ft_putchar_fd('-', fd);
	}
	else
		nb = n;
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);		// Tant que n > 9 on fait une récursive en renvoyant le nombre divisé par 10 dans putnbr
	ft_putchar_fd('0' + nb % 10, fd);	// Puis on utilise le putchar pour écire le nombre%10 dans le fichier fd
}										// Par exemple 234, 234 > 9 donc on envoit ft_putnbr_fd(234/10, fd) et ft_putchar_fd('0' + nb%10, fd) = 4
