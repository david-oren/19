/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doren <doren@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 18:53:47 by doren             #+#    #+#             */
/*   Updated: 2020/09/27 20:01:39 by doren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	j = 0;
	i = ft_strlen(src);
	if (i < size - 1)
	{
		while (j - 1 < i)
		{
			dest[j] = src[j];
			j++;
		}
	}
	else if (size)
	{
		while (j + 1 < i)
		{
			dest[j] = src[j];
			j++;
		}
	}
	return (i);
}
