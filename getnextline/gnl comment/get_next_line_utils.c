/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:56:29 by daoren            #+#    #+#             */
/*   Updated: 2021/04/29 17:16:27 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//utile pour gnljoin, strdup

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

// utile pour gnljoin strdup
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*new_dst;
	const char	*new_src;
	size_t		i;

	if (dst == NULL && src == NULL)		//ASK.... pourquoi && et pas ||
		return (NULL);
	new_dst = (char *)dst;			// memcpy avec void pas de souci pour prendre tout les caracteres non printable donc on cast en char pour
	new_src = (const char *)src;	// ne prendre que les caractere printale le \0 est deja implementer a ce moment dans dest.
	i = 0;
	while (i < n && new_src[i])		// verifie soit on arrive a n soit new source n est pas plus grand que n
	{
		new_dst[i] = new_src[i];
		i++;
	}
	new_dst[i] = 0;					// on termine dans tout les cas new dest par \0
	return (dst);			//sert a pointer vers le debut de new_dst
}


// GNLJOIN utile pour assembler (concatener) deux string en une nouvelle

char	*ft_gnljoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	dest = (char *)malloc(sizeof(char) * size);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, s1, ft_strlen(s1));
	ft_memcpy(dest + ft_strlen(s1), s2, ft_strlen(s2));		//il conmence au dernier indice de s1
	free((void *)s1);										// est necessaire pour vider s1 avant la prochaine jointure (voir bug maxlenul)
	return (dest);
}

// utile pour strchr remix 

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

// Une fonction qui va permettre de dupliquer une string a chaque foi qu on rencontre le \n

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
	free((void *)s);		// eviter les leaks
	return (NULL);
}
