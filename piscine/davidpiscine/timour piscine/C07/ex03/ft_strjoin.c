/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 13:38:39 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:01:34 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_len(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		count;
	char	*dest;

	i = -1;
	count = 0;
	while (++i < size)
		count += ft_len(strs[i]);
	if (size > 0)
		count += (size - 1) * ft_len(sep);
	if (!(dest = malloc((count + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	count = 0;
	while (++i < size)
	{
		ft_strcpy(dest + count, strs[i]);
		count += ft_len(strs[i]);
		if (i < size - 1)
			count += dest + count + ft_len(sep) - ft_strcpy(dest + count, sep);
	}
	dest[count] = 0;
	return (dest);
}
