/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mylib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 16:25:56 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/25 09:11:07 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <libgen.h>
# include <string.h>

void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_puterr(char *programme, char *filename, char *error);
void    ft_rewrite_userinput();
int     ft_open_file(char *filetitle);
void	ft_putstr(char *str);
void	ft_putstr_err(char *str);
int		ft_strlen(char *str);

#endif