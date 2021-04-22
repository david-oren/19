/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 20:19:44 by daoren            #+#    #+#             */
/*   Updated: 2021/04/22 16:20:52 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				gnl_cmp(char *str, char c)
{
	size_t		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char			*gnl_error(int fd, char **line)
{
	char		*buffer;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE < 1)
		return (NULL);
	if (!(buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (NULL);
	return (buffer);
}

ssize_t			gnl_return(char *save, ssize_t reader, char **line)
{
	if (!save && reader == 0)
		return (0);
	if (*line)
		return (1);
	return (-1);
}

void			*ft_memcpy(void *dst, const void *src, size_t n)
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

int				get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*save;
	ssize_t		reader;

	if (!(buffer = gnl_error(fd, line)))
		return (-1);
	reader = 1;
	while (!gnl_cmp(save, '\n') && reader > 0)
	{
		if ((reader = read(fd, buffer, BUFFER_SIZE)) < 0)
		{
			free((void*)buffer);
			return (-1);
		}
		buffer[reader] = 0;
		if (!(save = gnl_strjoin(save, buffer)))
			return (-1);
	}
	free((void *)buffer);
	if (!(*line = gnl_strdup(save, '\n')))
		return (-1);
	save = gnl_sve(save, '\n');
	if ((reader = gnl_return(save, reader, line)) == 0)
		return (0);
	return ((reader > 0) ? 1 : -1);
}
