/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:49:54 by daoren            #+#    #+#             */
/*   Updated: 2021/08/31 18:42:18 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_format_s(va_list ap, t_converter *c)
{
	char	*s;
	char	*input;
	int		size;

	input = va_arg(ap, char *);
	if (!input)
		input = "(null)";
	size = ft_strlen(input);
	if (0 <= c->precision && c->precision < size)
		size = c->precision;
	s = malloc(size + 1);
	if (!s)
		return (0);
	ft_strlcpy(s, input, size + 1);
	return (s);
}
