/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 03:54:53 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/27 18:17:12 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_num
{
	char *nbr;
	char *text_nbr;
}				t_num;

typedef struct	s_lines
{
	char	*num;
	int		j;
	int		wordindex;
	char	*currword;
	t_num	*new;
}				t_lines;

void			ft_putstr(char *str);
unsigned int	ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
void			write_numbers(char *file_name, char *number);
int				check_num(char *str);
void			print_result(t_num **dict, char *nbr);
char			*find_in_dict(t_num **dict, char *str);
void			write_suffix(unsigned int count, t_num **dict,
				int index, char *num);
int				test_if_end(int i, char *num);
int				is_space(char c);
void			ft_puttextnumber(char *str);
void			free_all(t_num **dict);
int				check_in_dict(t_num **dict, char *str);
int				check_suffix(unsigned int count, t_num **dict);
int				check_result(t_num **dict, char *nbr);
int				check_char_in_dict(t_num **dict, char c);
int				init_dict(char *file_name);
int				fill_dict(char *buffer, int length);
int				add_word(char *buffer, int index, int count, int tot_word);
int				count_lines(char *file_name);
int				check_units(char c, char d, char u, t_num **dict);
int				check_non_printable(t_num **dict);
int				check_units2(t_num **dict, char *arr);
void			print_units(char c, char d, char u, t_num **dict);
char			*find_char_in_dict(t_num **dict, char c);
void			pass_not_mod_print(t_num **dict, char *nbr,
				unsigned int *i, unsigned int count);
void			print_units2(t_num **dict, char *arr, char u);
int				check_init_and_num(int init_value, char *number, t_num **dict);
char			*setnum(char *buffer, int i, int *j, int count);
int				pass_spaces(char *buffer, int i, int *j, int count);
int				free_bulk(t_lines *bulk, int param);
int				not_only_space(int i, char *str);
void			print_zero(t_num **dict);

#endif
