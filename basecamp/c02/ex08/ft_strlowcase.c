/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 21:41:29 by daoren            #+#    #+#             */
/*   Updated: 2021/02/15 12:16:32 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) >= 'A' && *(str + i) <= 'Z')
		{
			*(str + i) = *(str + i) + 32;
		}
		i++;
	}
	return (str);
}

int    main(void)
{
    char str[100] = "HELLO THIS IS A TEST!!!! DID IT WORK";
    printf("result: %s", ft_strlowcase(str));
    return (0);
}
