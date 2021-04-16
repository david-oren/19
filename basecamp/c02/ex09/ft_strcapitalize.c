/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 21:41:27 by daoren            #+#    #+#             */
/*   Updated: 2021/02/15 19:36:37 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_is_alpha(char c)
{
	if (c < '0' || (c > '9' && c < 'A') || (c > 'Z' && c < 'a') || c > 'z')
	{
		return (1);
	}
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int a;

	a = 0;
	while (str[a] != '\0')
	{
		if (str[a] >= 'a' && str[a] <= 'z')
		{
			if (ft_is_alpha(str[a - 1]) == 1)
			{
				str[a] = str[a] - 32;
			}
		}
		else if (str[a] >= 'A' && str[a] <= 'Z')
		{
			if (ft_is_alpha(str[a - 1]) == 0)
			{
				str[a] = str[a] + 32;
			}
		}
		a++;
	}
	return (str);
}

int    main(void)
{
    char str[100] = "Hello,mf % *z-D-z mama how is it goIng?";
    printf("%s ", ft_strcapitalize(str));
}