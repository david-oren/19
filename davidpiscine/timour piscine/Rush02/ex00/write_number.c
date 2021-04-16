/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 04:06:06 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/27 14:20:02 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

t_num	**g_dict;

void	write_numbers(char *file_name, char *number)
{
	const int	init_value = init_dict(file_name);
	int			test;

	test = 0;
	if (!check_init_and_num(init_value, number, g_dict))
		return ;
	while (*number == '0')
		number++;
	if (!*number)
		print_zero(g_dict);
	else
	{
		test = check_result(g_dict, number);
		if (test > 0)
			print_result(g_dict, number);
		else
			test == 0 ? ft_putstr("Error") : ft_putstr("Dict Error");
	}
	write(1, "\n", 1);
	free_all(g_dict);
}

int		init_dict(char *file_name)
{
	char	buff[16384];
	int		filedesc;
	int		bufflen;
	int		num_of_lines;

	if ((num_of_lines = count_lines(file_name)) == -1)
		return (0);
	if (!(g_dict = malloc(sizeof(t_num *) * (num_of_lines + 1))))
		return (-2);
	g_dict[num_of_lines] = 0;
	if ((filedesc = open(file_name, O_RDONLY)) == -1)
		return (0);
	while ((bufflen = read(filedesc, buff, 16384)) > 0)
		if (!fill_dict(buff, bufflen))
			return (-1);
	if (close(filedesc) || bufflen)
		return (0);
	return (1);
}

int		fill_dict(char *buffer, int length)
{
	int i;
	int word_count;
	int inword;
	int tot_word;

	i = -1;
	tot_word = 0;
	inword = 0;
	word_count = 0;
	while (++i < length)
	{
		if (buffer[i] != '\n')
		{
			inword = 1;
			word_count++;
		}
		else if (inword)
		{
			add_word(buffer, i, word_count, tot_word);
			word_count = 0;
			inword = 0;
			tot_word++;
		}
	}
	return (1);
}

int		add_word(char *buffer, int i, int count, int tot_word)
{
	t_lines bulk;

	bulk.j = 0;
	bulk.num = 0;
	if (!(bulk.new = malloc(sizeof(t_num))))
		return (0);
	if (!(bulk.num = setnum(buffer, i, &(bulk.j), count)))
		return (free_bulk(&bulk, 0));
	if (!pass_spaces(buffer, i, &(bulk.j), count))
		return (0);
	bulk.wordindex = 0;
	if (!(bulk.currword = malloc(sizeof(char) * (count - bulk.j + 1))))
		return (free_bulk(&bulk, 1));
	bulk.j--;
	while (++bulk.j < count && ++(bulk.wordindex))
		bulk.currword[bulk.wordindex - 1] = buffer[i - count + bulk.j];
	bulk.currword[bulk.wordindex] = 0;
	bulk.new->nbr = bulk.num;
	bulk.new->text_nbr = bulk.currword;
	g_dict[tot_word] = bulk.new;
	return (1);
}

int		count_lines(char *file_name)
{
	char	buff;
	int		filedesc;
	int		bufflen;
	int		count;

	count = 0;
	if ((filedesc = open(file_name, O_RDONLY)) == -1)
		return (-1);
	while ((bufflen = read(filedesc, &buff, 1)) > 0)
		if (buff == '\n')
			count++;
	if (close(filedesc) == -1 || bufflen)
		return (-1);
	return (count);
}
