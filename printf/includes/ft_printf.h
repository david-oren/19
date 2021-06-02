/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:21:07 by daoren            #+#    #+#             */
/*   Updated: 2021/06/02 16:51:52 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct	s_printf_data
{
	va_list	argc;
	char	current_char;
	char	*current_str;
	int		minus;
	int		dot;
	int		zero;
	int		width;
	int		precision;
}				t_printf_data;

#endif
