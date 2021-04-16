/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:30:30 by daoren            #+#    #+#             */
/*   Updated: 2021/04/13 16:26:38 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)			// Static car on utilise cette fonction uniquement ici et pas dans toute la libft
{						// Compter combien il y a de nombres dans l'int n
						// On utilise pas str_len parceque par exemple si l'int envoyé correspond à 00975, strlen renvoie 5, alors qu'en réalité on a 3 chiffres.
	unsigned int	i;
						
	i = 0;	
	if (!(n))				// On gère le cas d'erreur ou n n'existe pas, on retourne 1	
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long			i;		// On va faire i  = ft_count(n)
	unsigned long	nb;			// On cast le n de int ver unsigned long
	char			*str;
	int				neg;

	nb = n;
	neg = 0;
	if (n < 0)
	{
		nb *= -1;
		neg = 1;
	}
	i = ft_count(n);
	str = (char *) malloc(sizeof(char) * (ft_count(n) + 1));	// On protège le malloc le nombre donné par ft_count + 1 (à cause du Null terminating character) 
									// multiplié par un sizeof de char.
									// Pourquoi on met un char * après str =  ???? 
	if (!str)
		return (NULL);						// Dans le cas où str n'existe pas on retourne juste NULL
	str[i] = '\0';							// Quand on arrive à la fin de la string
	
	if (n < 0)							// Si n est plus petit que 0 alors on écrit un signe - au début de la string
		str[0] = '-';
	while (i-- > neg)
	{
		str[i] = (nb % 10) + '0';				// Formule de atoi à l'envers. 
									// Exemple nb = 234, on prend 234%10 = 4, qu'on transforme de int vers string avec le +'0'
		nb /= 10;						// Ensuite 234/10 = 23 car c'est un int et etc
	}
	return (str);
}
