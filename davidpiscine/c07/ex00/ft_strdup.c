/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doren <doren@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 20:20:52 by doren             #+#    #+#             */
/*   Updated: 2020/09/29 18:02:49 by doren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char				*ft_strdup(char *str)
{
	int		i;
	char	*dest;

	i = ft_strlen(str);
	if (!(dest = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (str[++i])
		dest[i] = str[i];
	dest[i] = '\0';
	return (dest);
}
