/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseo <aseo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:39:00 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/25 13:53:11 by aseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

void	sigcatch()
{
	write(2, "Your GNL got killed because it got stuck \n", 42);
	exit(-1);
}

void
	test_fd(char **buffer, char const *filename, int fd)
{
	int	r;

	alarm(5);
	signal(SIGALRM, sigcatch);
	if (fd == STDIN_FILENO)
		printf("Reading stdin...\n---\n");
	else
		printf("Reading %s...\n---\n", filename);

	while ((r = get_next_line(fd, buffer)) > 0)
	{
		printf("%2d-%s\n", r, *buffer);
		if (*buffer)
		{
			free(*buffer);
			*buffer = NULL;
		}

	}

	if (r >= 0)
		printf("%2d-%s\n---\n", r, *buffer);
	else
		printf("%2d#error\n---\n", r);

	if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	alarm(0);
}

int
	main(void)
{
	char		*buffer = NULL;
	int			i, fd;
	int			test_count;
	char const	*tests[100] = {
		"tests/simple",
		"tests/empty",
		"tests/empty_one",
		"tests/multi_in_one",
		"tests/many_lines",
		"tests/over_buffer",
		"tests/63_line",
		"tests/63_line_nl",
		"tests/64_line",
		"tests/64_line_nl",
		"tests/65_line",
		"tests/65_line_nl",
		"tests/baudelaire.txt",
		"tests/large_file.txt",
		"tests/lorem_ipsum",
		//"tests/one_big_fat_line.txt",
		//"tests/Mr. Justice Maxell by Edgar Wallace.txt",
		NULL
	};

	test_count = 0;
	while (tests[test_count])
		test_count++;
	i = 0;
	while (i < test_count)
	{
		fd = open(tests[i], O_RDONLY);
		test_fd(&buffer, tests[i++], fd);
		close(fd);
	}
	test_fd(&buffer, "Invalid file descriptor", 42);
	test_fd(&buffer, NULL, STDIN_FILENO);
	return (0);
}
