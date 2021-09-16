/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 03:28:38 by daoren            #+#    #+#             */
/*   Updated: 2021/09/16 03:28:53 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_print
{
	int	flag_zero;
	int	flag_minus;
	int	width;
	int	prec;
	int	res;
}		t_print;

int		ft_print_char(va_list ap, t_print *opt, int char_printed);
int		ft_print_str(va_list ap, t_print *opt, int char_printed);
int		ft_print_nil(t_print *opt, int char_printed);
int		ft_print_ptr(unsigned long long nbr, t_print *opt, int c, char *base);
int		ft_print_mod(t_print *opt, int char_printed);
int		ft_print_zero(t_print *opt, int char_printed);
int		ft_print_flags(t_print *opt, int len, long long nbr, char *base);
int		ft_print_no_flags(t_print *opt, int len, long long nbr, char *base);
int		ft_print_di(long int nbr, t_print *opt, int char_printed, char *base);
int		ft_print_uxx(unsigned long nbr, t_print *opt, int c, char *base);
int		ft_reached_convspecifier(const char *str);
int		ft_parse_flags(const char *str, t_print *opt, int i);
int		ft_convspecifier(const char *str, va_list ap, t_print *opt);
int		ft_printf(const char *format, ...);

#endif
