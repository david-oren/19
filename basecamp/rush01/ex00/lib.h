/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 19:23:05 by daoren            #+#    #+#             */
/*   Updated: 2021/02/22 11:36:17 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

int		ft_checkmate(char *cleaned_input);
int		ft_checkmate_2(char *cleaned_input, int checkmate, int i);
int		solution(int *ptr, char argv[1]);
void	printtab(void);
int		check_view(int *column, int constraint);
int		check_is_full(int tab[4][4]);
void	ft_putchar(char c);
int		ft_strlen(char *str);
char	ft_display_error_message(char *src);
void	ft_clean_input(char src[], char copy[]);

#endif

creation du .h pour mettre tt nos proto et pouvoir les utiliser dans nos autres fct