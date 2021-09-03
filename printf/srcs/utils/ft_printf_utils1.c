/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 18:12:42 by daoren            #+#    #+#             */
/*   Updated: 2021/08/31 19:04:36 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	write_and_add(int *count, char c)
{
	write(1, &c, 1);
	(*count)++;
}

void	write_str_and_add(t_printf_data *pf_var, int *count)
{
	int len_c;

	if (pf_var->current_char)
	{
		if (pf_var->current_char == 'c')
		{
			len_c = pf_var->width > 0 ? pf_var->width : 1;
			write(1, pf_var->current_str, len_c);
			(*count) += len_c;
		}
		else
		{
			write(1, pf_var->current_str, ft_strlen(pf_var->current_str));
			(*count) += ft_strlen(pf_var->current_str);
		}
	}
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*dest;

	i = ft_strlen(str);
	if (!(dest = malloc((i + 1) * sizeof(char))))
	{
		return (NULL);
	}
	i = -1;
	while (str[++i])
		dest[i] = str[i];
	dest[i] = 0;
	return (dest);
}

char	*ft_strdup_spec(const char *str)
{
	if (!str)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	int		i;
	size_t	str_len;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		if (!(str = malloc(sizeof(char))))
			return (NULL);
		str[0] = 0;
		free(s);
	}
	else
	{
		i = -1;
		str_len = len < ft_strlen(s) - start ? len : ft_strlen(s) - start;
		if (!(str = malloc(sizeof(char) * (str_len + 1))))
			return (NULL);
		while (s[++i] && i < (int)len)
			str[i] = s[start + i];
		str[str_len] = 0;
		free(s);
	}
	return (str);
}
