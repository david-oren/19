/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 17:02:58 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:07:19 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mylib.h"

int	ft_open_file(char *filetitle)
{
	char	buff[16384];
	int		filedesc;
	int		bufflen;

	if ((filedesc = open(filetitle, O_RDONLY)) == -1)
		return (-1);
	while ((bufflen = read(filedesc, buff, 16384)) > 0)
		ft_putstr(buff);
	close(filedesc);
	if (bufflen)
		return (-1);
	return (0);
}
