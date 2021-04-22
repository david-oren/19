/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:25:43 by daoren            #+#    #+#             */
/*   Updated: 2021/04/23 00:27:59 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*ft_check_error(int fd, char **line);
int		ft_backslash_checker(char *str);
char	*ft_get_line(char *str);
int		ft_return(char **buff, int i, char **line, char **str_save);
int		get_next_line(int fd, char **line);

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_gnljoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_strchr_dup_remix(const char *s, int c);

#endif
