/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 18:01:30 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 18:59:12 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	tot;

	if (ft_strlen(dest) < size)
		tot = ft_strlen(src) + ft_strlen(dest);
	else
		tot = size + ft_strlen(src);
	while (*(dest++) && size)
		size--;
	dest--;
	i = -1;
	while (src[++i] && i < size - 1 && size)
		dest[i] = src[i];
	if (size)
		dest[i] = 0;
	return (tot);
}
