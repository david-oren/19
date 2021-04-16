/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 09:22:46 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 18:58:35 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		not_alpha_num(char str)
{
	if (('a' <= str && str <= 'z') || ('A' <= str && str <= 'Z')
	|| ('0' <= str && str <= '9'))
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] += 32;
	}
	if ('a' <= str[0] && str[0] <= 'z')
		str[0] -= 32;
	i = 0;
	while (str[++i] != '\0')
	{
		if (('a' <= str[i] && str[i] <= 'z') && not_alpha_num(str[i - 1]))
			str[i] -= 32;
	}
	return (str);
}
