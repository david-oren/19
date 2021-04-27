/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:56:29 by daoren            #+#    #+#             */
/*   Updated: 2021/04/27 15:40:04 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//utile pour gnljoin, strdup...................

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

// utile pour gnljoin strdup...........................

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*new_dst;
	const char	*new_src;
	size_t		i;

	if (dst == NULL && src == NULL)
		return (NULL);
	new_dst = (char *)dst;
	new_src = (const char *)src;
	i = 0;
	while (i < n)
	{
		new_dst[i] = new_src[i];
		i++;
	}
	return (dst);
}


// utile pour la fct principale get next line qui va permettre de gerer les copies des lignes ....................

char	*ft_gnljoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	size;
	size_t	i;

	i = -1;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest = (char *)malloc(sizeof(char) * size);
	while (++i < size)
		dest[i] = 0;
	if (!dest)
	{
		if (s1)
			free((void *)s1);
		return (NULL);
	}
	ft_memcpy(dest, s1, ft_strlen(s1));
	ft_memcpy(dest + ft_strlen(s1), s2, ft_strlen(s2));
	free((void *)s1);
	return (dest);
}

// utile pour strchr remix..............

char	*ft_strdup(const char *s1)
{
	char	*new_s1;
	int		i;

	i = ft_strlen(s1) + 1;
	new_s1 = (char *)malloc(sizeof(char) * i);
	if (!(new_s1))
		return (0);
	ft_memcpy(new_s1, s1, i);
	return (new_s1);
}

// Une fonction qui va permettre de dupliquer une string a chaque ..........................

char	*ft_strchr_dup_remix(const char *s, int c)
{
	char	*dest;
	int		i;

	if (!s)
		return (NULL);
	i = -1;
	while (s[++i])
	{
		if (s[i] == (char)c)
		{
			dest = ft_strdup((char *)(s + i + 1));
			free((void *)s);		// eviter les leaks
			return (dest);
		}
	}
	free((void *)s);		// eviter les leaks.....................
	return (NULL);
}
