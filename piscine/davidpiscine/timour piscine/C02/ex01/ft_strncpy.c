/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 21:39:26 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 18:58:18 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	int				end;

	end = 1;
	i = -1;
	while (++i < n)
	{
		if (src[i] != '\0' && end)
		{
			dest[i] = src[i];
		}
		else if (end && src[i] == '\0')
		{
			dest[i] = '\0';
			end = 0;
		}
		else
			dest[i] = '\0';
	}
	return (dest);
}
