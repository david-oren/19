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

int				ft_printf(const char *format, ...);
int				init_struct(t_printf_data *pf_var);
void			print_struct(t_printf_data *pf_var);
size_t			ft_strlen(const char *str);
int				is_in_str(char *str, char c);
int				ft_pf_atoi(t_printf_data *pr_var, const char *str, int *index);
int				ft_stringify(t_printf_data *pf_var);
void			write_and_add(int *count, char c);
void			write_str_and_add(t_printf_data *pf_var, int *count);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strdup_spec(const char *str);
char			*ft_strdup(const char *str);
int				free_and_return(char *to_free, int ret);
char			*join_back(char *malloced, char *add);
char			*join_front(char *malloced, char *add);
char			*string_with_length(char c, int length);
char			*ft_itoa_base(int n, int base_len, const char *base);
char			*ft_itoa_base_u(unsigned int n, int base_len, const char *base);
char			*ft_itoa_base_p(unsigned long long int n,
				int base_len, const char *base);

int				convert_s(t_printf_data *pf_var);
int				convert_c(t_printf_data *pf_var);
int				convert_percent(t_printf_data *pf_var);
int				convert_di(t_printf_data *pf_var);
int				convert_p(t_printf_data *pf_var);
int				convert_u(t_printf_data *pf_var);
int				convert_x(t_printf_data *pf_var);
int				convert_upperx(t_printf_data *pf_var);
int				convert_width(t_printf_data *pf_var);

#endif
