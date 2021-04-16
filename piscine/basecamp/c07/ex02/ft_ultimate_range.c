/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 21:50:41 by daoren            #+#    #+#             */
/*   Updated: 2021/02/24 13:20:45 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int interval;  //variable pour avoir le nbr d element entre min et max
	
	i = -1;  // pour qu il commence a zero dans mon while
	if ( min >= max ) // si min est plus grand alors il faut arreter si il ets egal il doit retournre zero
	{
		*range = 0; // faire pointer le tableau a zero
		return (0);
	}
	interval = max - min; // pour avoir le nbr d element entre min et max
	*range = malloc(interval * sizeof(int)); // pour pouvoir allouer de la memoire
	if (!*range) // securiser cette memoire si il plante
		return (-1); // si pb il faut retrouner -1
	while (++i < interval) // la boucle pour remplir le tableau avec les element entre min inclu et max exclu
		(*range)[i] = min + i; // rempli le tableau
	return (interval); // renvoyer le nbr d element entre min et max
}

//ex02
#include <stdio.h>
int main () {
    int **range;
    printf("%i", ft_ultimate_range(range, 2, 10));
    printf("%i", range[0][10]);
    return 0;    
}