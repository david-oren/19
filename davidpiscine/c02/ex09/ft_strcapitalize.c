/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doren <doren@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 18:29:21 by doren             #+#    #+#             */
/*   Updated: 2020/09/27 20:01:38 by doren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_lettre(char c)
{
	return ((c >= '0' && c <= '9') ||
			(c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	if (str[0] && str[0] >= 'a' && str[0] <= 'z')
	{
		str[0] = str[0] - 32;
		i++;
	}
	while (str[i] != '\0')
	{
		if (!ft_lettre(str[i - 1]) && (str[i] >= 'a' && str[i] <= 'z'))
			str[i] = str[i] - 32;
		else if (ft_lettre(str[i - 1]) && (str[i] >= 'A' && str[i] <= 'Z'))
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
