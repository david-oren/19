/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:39:00 by ncolomer          #+#    #+#             */
/*   Updated: 2019/10/28 08:39:35 by jpanneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "../../get_next_line.h"

void
	test_fd(char **buffer, char const *filename, int fd)
{
	int	r;

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
}

int
	main(void)
{
	char		*buffer = NULL;
	int			i, fd;
	int			test_count;
	char const	*tests[100] = {
		"test/simple",
		"test/empty",
		"test/empty_one",
		"test/multi_in_one",
		"test/many_lines",
		"test/over_buffer",
		"test/63_line",
		"test/63_line_nl",
		"test/64_line",
		"test/64_line_nl",
		"test/65_line",
		"test/65_line_nl",
		"test/lorem_ipsum",
		//"tests/Mr. Justice Maxell by Edgar Wallace.txt",
		NULL
	};

	test_count = 0;
	while (tests[test_count])
		test_count++;
	printf("**********************\n* BUFFER_SIZE %6d *\n**********************\n", BUFFER_SIZE);
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
