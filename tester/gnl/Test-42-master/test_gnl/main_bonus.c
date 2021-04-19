/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpanneau <jpanneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 09:01:12 by jpanneau          #+#    #+#             */
/*   Updated: 2019/10/28 09:23:56 by jpanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int		tabs_equal(int truc, int *tabs, size_t size)
{
	while (size--)
	{
		if (*tabs++ != truc)
			return (0);
	}
	return (1);

}

int		main(int ac, char **av)
{
	if (ac >= 2)
	{
		int		i = 0;
		int		fd[ac - 1];
		int 	ret[ac - 1];
		char	*line = NULL;
		int		s_line = 0;

		while (i < ac - 1)
		{
			fd[i] = open(av[i + 1], O_RDONLY);
			i++;
		}

		i = 0;
		while (i < ac - 1)
			ret[i++] = 2;

		while (!tabs_equal(0, ret, ac - 1))
		{
			i = 0;
			while (i < ac - 1)
			{
				ret[i] = get_next_line(fd[i], &line);
				if (line)
				{
					printf("ret : %d | FILE\033[1;31m%s: %d\033[0m\t", ret[i], av[i + 1], s_line);
					printf("%s\n", line);
				}
				if (line)
					free(line);
				i++;
			}
			if (ret[i -1] == -1)
				break;
			s_line++;
		}
	}
	if (ac == 1)
	{
		int fd = 0;
		int num = 0;
		char *line = NULL;
		int ret = 2;

		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf("ret : %d | %d   %s\n", ret, ++num, line);
			if (line)
				free(line);
		}
		printf("Return equals to : %d", ret);
	}
	return (0);
}
