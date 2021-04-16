/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 21:32:33 by daoren            #+#    #+#             */
/*   Updated: 2021/04/13 02:25:36 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(int i, char **dest)
{
	while (i)
		free(dest[--i]);
	free(dest);
}

static int	ft_strlen_remix(char const *s, char c)
{
	int	i;

	i = 0;
	while (s && s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_word_number(char const *s, char c)
{
	int	i;
	int	w;

	w = 0;
	i = 0;
	while (s && s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			w++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (w);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		wnb;
	int		i;

	wnb = ft_word_number(s, c);
	dest = (char **)malloc(sizeof(char *) * (wnb + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < wnb)
	{
		while (s && *s && *s == c)
			s++;
		dest[i] = ft_substr(s, 0, ft_strlen_remix(s, c));
		if (!dest)
		{
			ft_free(i, dest);
			return (NULL);
		}
		s += ft_strlen_remix(s, c);
		i++;
	}
	dest[i] = 0;
	return (dest);
}
