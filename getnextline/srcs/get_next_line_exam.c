/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_exam.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:59:08 by daoren            #+#    #+#             */
/*   Updated: 2021/04/26 18:01:43 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int		ft_strchr(char *buf)
{
	int		i;

	i = -1;
	while(buf && buf[++i])
		if(buf[i] == '\n')
			return(i);
	return(-1);
}

char	*ft_strjoin(char	*s1, char	*buf)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(s1 && s1[i] && s1[i] != '\n')
		i++;
	while(buf && buf[j] && buf[j] != '\n')
		j++;
	if (!(str = malloc(i + j + 1)))
		return(NULL);
	i = 0;
	j = 0;
	while(s1 && s1[i] && s1[i] != '\n')
		str[i++] = s1[j++];
	while(buf && *buf && *buf != '\n')
		str[i++] = *buf++;
	str[i] = 0;
	free(s1);
	return(str);
}

int		get_next_line(char **line)
{
	static char		buf[33];
	int		i;
	int		ret;

	if (!line || !(*line = ft_strjoin(NULL, buf)))
		return (-1);
	ret = 1;
	while (ft_strchr(buf) == -1 && ret && ret != -1)
	{
		ret = read(0, buf, 32);
		buf[ret] = 0;
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
	}
	if (buf[0] == '\0')
		return (0);
	i = 0;
	ret = ft_strchr(buf) + 1;
	while (buf[ret] && ret)
		buf[i++] = buf[ret++];
	buf[i] = 0;
	return(1);
}
