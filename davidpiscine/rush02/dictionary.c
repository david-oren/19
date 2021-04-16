/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 12:09:16 by vmasse            #+#    #+#             */
/*   Updated: 2020/09/26 18:06:33 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "struct.h"
#include <stdlib.h>
void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int main()
{
	char buffer_to_read[1];
	int file;
	int line_cursor;
	t_num *dict;

	file = open("dictionary.txt", O_RDONLY);
    if (file < 0)
        write(1, "Error", 5);

	// allocate memory for the array of t_num
	dict = malloc(sizeof(t_num));

	// running through the file and adding keys and values
	line_cursor = 0;
	while (read(file, buffer_to_read, 1) > 0)
	{
		if (buffer_to_read[0] != 10)
		{
			ft_putstr(buffer_to_read);
			//dict[line_cursor].key = &buffer_to_read[0];
			//dict[line_cursor].value = "zero";
			//printf("%s\n%s\n", dict[0].key, dict[0].value);
			// run through until :
			//  is it first space(s) or char(s) ?

			// check_if_dictionary_is_valid
			// malloc()
			// create structure
		}
		printf("\n");
		line_cursor++;
	}
	return (0);
}

char	*open_file()
{}

t_num	*create_dictionary()
{

}

