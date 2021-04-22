/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:56:29 by daoren            #+#    #+#             */
/*   Updated: 2021/04/22 16:21:30 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*gnl_strdup(char *save, char c)
{
	char	*new_s1;
	int		i;

	i = 0;
	while (save[i] != c && save[i])
		i++;
	if (!(new_s1 = malloc(sizeof(char) * i + 1)))
	{
		free((void *)save);
		return (NULL);
	}
	i = 0;
	while (save[i] != c && save[i])
	{
		new_s1[i] = save[i];
		i++;
	}
	new_s1[i] = 0;
	return (new_s1);
}

int			gnl_if_free(char *s1, int j, char *s2)
{
	s1[j] = 0;
	free(s2);
	if (!s1[0])
	{
		free((void *)s1);
		return (0);
	}
	return (1);
}

char		*gnl_sve(char *save, char c)
{
	int		i;
	int		j;
	char	*new_s1;
	int		size;

	i = 0;
	j = 0;
	while (save[i] != c && save[i])
		i++;
	if (save[i] == c)
		i++;
	size = ft_strlen(&save[i]);
	if (!(new_s1 = malloc(sizeof(char) * size + 1)))
	{
		free((void *)save);
		return (NULL);
	}
	while (save[i])
	{
		new_s1[j] = save[i];
		j++;
		i++;
	}
	i = gnl_if_free(new_s1, j, save);
	return (i ? new_s1 : 0);
}

char		*gnl_strjoin(char *s1, char *s2)
{
	char	*new_s;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(new_s = malloc(sizeof(char) * (size + 1))))
	{
		if (s1)
			free((void *)s1);
		free(s2);
		return (0);
	}
	ft_memcpy(new_s, s1, ft_strlen(s1));
	ft_memcpy(new_s + ft_strlen(s1), s2, ft_strlen(s2));
	free((void *)s1);
	new_s[size] = '\0';
	return (new_s);
}

size_t		ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
