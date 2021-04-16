/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 08:53:45 by loverhae          #+#    #+#             */
/*   Updated: 2021/02/22 11:27:35 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <unistd.h>

int		check_view(int *column, int constraint)
{
	int count;								 nbr de batiment
	int min;								taille du batiment
	int i;    								  incrementation

	count = 1; 									car on voit -1 batiment
	min = column[0]; 								premier element
	i = 1;									les valeurs de 0 sont deja rentre
	while (i < 4)
	{
		count += (column[i] > min) ? 1 : 0;		
		min = (column[i] > min) ? column[i] : min;  changer le min si la colone est plus grande
		i++;
	}
	return (count == constraint);  on compare la contrainte au count optenu
}

int		check_is_full(int tab[4][4])		parcour le tableau et des qu il trouve une case vide alors il considere que c ets pas fini 
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (!tab[i][j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

char	ft_display_error_message(char *src)		voir si l input est correct
{
	int size_input;
	int i;

	i = 0;
	size_input = ft_strlen(src);			
	if (size_input != 31)			digit (16) + espace (15)
	{
		ft_putstr("error\n");
		return (0);
	}
	while (src[i] != '\0')		si c ets pas un chiffre d 1 a 4 et si c ets pas un espace 
	{
		if (src[i] < 49 || src[i] > 52)
			if (src[i] != 32)
				ft_putstr("error\n");
		i++;
	}
	return (0);
}
