/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkravetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:43:14 by mkravetz          #+#    #+#             */
/*   Updated: 2019/12/17 16:58:24 by mkravetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int		main(int ac, char **av)
{
	char	*line;
	int		nb_line;
	int		fd;
	int		fd2;
	int		fd3;

	if (ac < 3)
		return (0);
	nb_line = 1;
	if ((fd = open(av[1], O_RDONLY)) == -1)
		printf("le fichier n'existe pas.");
	if ((fd2 = open(av[2], O_RDONLY)) == -1)
		printf("le fichier n'existe pas.");
	if ((fd3 = open(av[3], O_RDONLY)) == -1)
		printf("le fichier n'existe pas.");
	line = NULL;
	int ret = 0;
	while ((ret = get_next_line(fd, &line)) > 0 && nb_line)
	{
		printf("line[%d]: %s\n", nb_line, line);
		free(line);
		line = NULL;
		ret = get_next_line(fd2, &line);
		printf("line[%d]: %s\n", nb_line, line);
		free(line);
		line = NULL;
		ret = get_next_line(fd3, &line);
		printf("line[%d]: %s\n", nb_line, line);
		free(line);
		nb_line++;
	}
	printf("line[%d]: %s\n", nb_line, line);
	free(line);
	line = NULL;
	ret = get_next_line(fd2, &line);
	printf("line[%d]: %s\n", nb_line, line);
	free(line);
	line = NULL;
	ret = get_next_line(fd3, &line);
	printf("line[%d]: %s\n", nb_line, line);
	free(line);
	//	system("leaks a.out");
}
