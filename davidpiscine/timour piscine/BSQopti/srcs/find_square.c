/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 22:01:39 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/30 12:28:13 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int		read_first_line(t_grid_prop *grid, char *file_title)
{
	char	buff[128];
	int		filedesc;
	int		bufflen;
	int		i;

	i = -1;
	grid->first_ligne_len = 0;
	if ((filedesc = open(file_title, O_RDONLY)) == -1)
		return (0);
	if ((bufflen = read(filedesc, buff, 128)) > 0)
	{
		grid->height = ft_atoi(buff);
		while (buff[++i] >= '0' && buff[i] <= '9')
			grid->first_ligne_len++;
		grid->empty = buff[i];
		grid->notempty = buff[i + 1];
		grid->square = buff[i + 2];
	}
	if (!test_char_in_grid(grid))
		return (close(filedesc) * 0);
	grid->first_ligne_len += 4;
	if (close(filedesc) == -1 || bufflen == -1)
		return (0);
	return (1);
}

int		count_columns(t_grid_prop *grid, char *file_title)
{
	char			buff[1];
	int				filedesc;
	int				bufflen;
	unsigned int	count;
	int				first;

	count = 0;
	first = 1;
	if ((filedesc = open(file_title, O_RDONLY)) == -1)
		return (0);
	while ((bufflen = read(filedesc, buff, 1)) > 0)
	{
		if (buff[0] == '\n' && !first)
			break ;
		else if (buff[0] == '\n')
			first = 0;
		else if (!first)
			count++;
	}
	grid->width = count;
	if (close(filedesc) == -1 || bufflen == -1 || count == 0)
		return (0);
	return (1);
}

void init_first_line(t_fill_up_grid *loc, int *first_line, const t_grid_prop *grid_info)
{
	unsigned int i;

	i = -1;
	while (++i < grid_info->width)
	{
		if (loc->buff[i] == grid_info->notempty)
			first_line[i] = 0;
		else
			first_line[i] = 1;
	}
}

t_fill_up_grid		fill_up_grid(char *grid, const t_grid_prop *grid_info, char *file_title)
{
	t_fill_up_grid loc;
	unsigned int i;
	unsigned int lineindex;
	int *lastline;
	int *currline;
	int *temp;

	lastline = malloc(sizeof(int) * grid_info->height);
	currline = malloc(sizeof(int) * grid_info->height);
	currline[0] = 1;
	loc = c_fill_up_grid();
	loc.buff = grid;
	loc.fd = open(file_title, O_RDONLY);
	read(loc.fd, loc.buff, grid_info->first_ligne_len);
	loc.bufflen = read(loc.fd, loc.buff, (grid_info->width + 1) * grid_info->height);
	init_first_line(&loc, lastline, grid_info);
	i = 0;
	while (++i < grid_info->height)
	{
		lineindex = -1;
		while (++lineindex < grid_info->width)
		{
			if (loc.buff[i * (grid_info->width + 1) + lineindex] == grid_info->notempty)
				currline[lineindex] = 0;
			else if (lineindex == 0)
			{
				currline[lineindex] = 1;
				if (loc.max < 1)
					change_max(&loc, 1, i * grid_info->width + lineindex);
			}
			else
			{
				if ((currline[lineindex] = get_min(lastline, currline, lineindex) + 1) > loc.max)
					change_max(&loc, currline[lineindex], i * (grid_info->width + 1) + lineindex);
			}
		}
		temp = lastline;
		lastline = currline;
		currline = temp;
	}
	free(loc.buff);
	return (loc);
}

void	find_square(char *file_title)
{
	t_grid_prop	grid_info;
	char			*main_grid;
	t_fill_up_grid			index;

	if (!read_first_line(&grid_info, file_title))
		return (ft_puterr("map error\n"));
	if (!count_columns(&grid_info, file_title))
		return (ft_puterr("map error\n"));
	if (!(main_grid = malloc(sizeof(char) * ((grid_info.width + 1) * grid_info.height))))
		return (ft_puterr("Malloc error\n"));
	if ((index = fill_up_grid(main_grid, &grid_info, file_title)).index_of_max < 0)
	{
		free(main_grid);
		if (index.index_of_max == -2)
			return (ft_puterr("map error\n"));
		else
			return (ft_puterr("malloc error\n"));
	}
	print_result(main_grid, grid_info, index);
}
