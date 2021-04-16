/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 21:50:27 by daoren            #+#    #+#             */
/*   Updated: 2021/02/24 20:14:31 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int i;
	int *str;

	i = 0;
	if (min >= max)
		return(0);
	str = malloc((max - min) * sizeof(int));
	if (str == (NULL))
		return (NULL);
	while (i < max - min)
	{
		str[i] = min + i;
		i++;
	}
	return (str);
}

// ft_range
#include <string.h>
#include <stdio.h>

void    ft_aff_tab(int *tab, int rge)
{
    int    i;

    i = 0;
    if (!(tab))
        printf("tab vide");
    else
        while (i < rge)
        {
            printf("%i ", tab[i++]);
        }
    printf("\n");
}

int        main(void)
{
    int    min;
    int    max;
    int    *tab;
    int    rge;
    
    // MAX > MIN
    min = -4;
    max = 2;
    rge = ft_abs(max - min);
    tab = ft_range(min, max);
    printf("--- MAX > MIN ---\nmin : %i, max : %i; range : %i\n", min, max, rge);
    ft_aff_tab(tab, rge);
    
    min = -2147483648;
    max = -2147483647;
    rge = ft_abs(max - min);
    tab = ft_range(min, max);
    printf("\nmin : %i, max : %i; range : %i\n", min, max, rge);
    ft_aff_tab(tab, rge);

    // MIN >= MAX
    min = -4;
    max = -6;
    rge = ft_abs(max - min);
    tab = ft_range(min, max);
    printf("\n--- MIN >= MAX ---\nmin : %i, max : %i; range : %i\n", min, max, rge);
    ft_aff_tab(tab, rge);
    
    min = 8;
    max = 6;
    rge = ft_abs(max - min);
    tab = ft_range(min, max);
    printf("\nmin : %i, max : %i; range : %i\n", min, max, rge);
    ft_aff_tab(tab, rge);
    
    min = -2147483648;
    max = -2147483648;
    rge = ft_abs(max - min);
    tab = ft_range(min, max);
    printf("\nmin : %i, max : %i; range : %i\n", min, max, rge);
    ft_aff_tab(tab, rge);
    
    min = -2147483647;
    max = -2147483648;
    rge = ft_abs(max - min);
    tab = ft_range(min, max);
    printf("\nmin : %i, max : %i; range : %i\n", min, max, rge);
    ft_aff_tab(tab, rge);

    min = 0;
    max = 0;
    rge = ft_abs(max - min);
    tab = ft_range(min, max);
    printf("\nmin : %i, max : %i; range : %i\n", min, max, rge);
    ft_aff_tab(tab, rge);

    return (1);
}
