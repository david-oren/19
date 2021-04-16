/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 14:06:20 by daoren            #+#    #+#             */
/*   Updated: 2021/04/13 15:48:50 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_power_of_10(int nb, int power)  //Elle prend 2 paramètres 1 nombre et la puissance de 10 de ce nombre qu’on veut avoir

{
	while (--power > 0)						//La boucle va décrémenter la puissance et à chaque fois multiplié le nombre par 10
		nb = nb * 10;						//Jusqu’à ce que la puissance vaut 0
	return (nb);
}

int	ft_atoi(const char *str)
{
	int					sign;			// variable qui s occupe du signe
	int					i;				// variable pour se balader
	unsigned long long	return_nb;		// valeur de retour

	sign = 1;
	i = 0;
	return_nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)	// tant que le caractere est un espace ou un carac non imprimable
		str++;												// on increment
	if (str[i] == ' ' || str[i] == '-' || str[i] == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (str[i] >= '0' && str[i] <= '9')		// tant que c est un chiffre
		i++;
	if ((i >= 19 || return_nb > 1ull << 63) && sign > 0)	// gerer si il y a plus de 19 caractere ou c est un LLmax (ULL = unsigend long long) et que c est + << operateur bitchift
		return (-1);
	else if ((i >= 19 || return_nb > 1ull << 63) && sign < 0) // gerer si il y a plus de 19 caractere ou c est un LLmin (ULL = unsigend long long) et que c est -
		return (0);
	while (i > 0)											// formule d atoi avec la fct 
		return_nb += ft_power_of_10(*(str++) - '0', i--);  // Pour chacun des i qu'on a incrémenté on envoyé les chiffre de la chaîne de character dans un une fonction qui va les transformer en int. On donne la va leur a return_nb
	return (return_nb * sign); // on retourne le resultat foi le signe
}
