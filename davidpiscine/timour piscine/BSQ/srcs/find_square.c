/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 22:01:39 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/30 18:23:40 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

int g_bool = 0;

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
	if (close(filedesc) == -1 || bufflen == -1 || buff[i + 3] != '\n')
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

void	big_while(t_fill_up_grid *loc, const t_grid_prop *grid_info, int *grid)
{
	while ((loc->bufflen = read(loc->fd, loc->buff, grid_info->width + 1)) > 0)
	{
		loc->i = -1;
		while (++loc->i < loc->bufflen && loc->buff[loc->i] != '\n')
		{
			if (loc->buff[loc->i] == grid_info->notempty)
				grid[loc->index] = 0;
			else if (loc->buff[loc->i] != grid_info->empty)
				loc->error = 1;
			else if (loc->index < grid_info->width)
			{
				grid[loc->index] = 1;
				grid[loc->index] > loc->max ? change_max(loc, grid) : 0;
			}
			else if (loc->i == 0)
			{
				grid[loc->index] = 1;
				grid[loc->index] > loc->max ? change_max(loc, grid) : 0;
			}
			else if (((grid[loc->index] = get_min(grid, grid_info,
					loc->index) + 1) > loc->max))
				change_max(loc, grid);
			loc->index++;
		}
		g_bool = ((unsigned int)loc->bufflen != grid_info->width + 1) && loc->bufflen > 0;
	}
}

int		fill_up_grid(int *grid, const t_grid_prop *grid_info, char *file_title)
{
	t_fill_up_grid loc;

	loc = c_fill_up_grid();
	if ((loc.fd = open(file_title, O_RDONLY)) == -1)
		return (-2);
	if (!(loc.buff = malloc(sizeof(char) * (grid_info->width + 1))))
		return (close(loc.fd) * 0 - 1);
	read(loc.fd, loc.buff, grid_info->first_ligne_len);
	big_while(&loc, grid_info, grid);
	free(loc.buff);
	if (close(loc.fd) == -1 || loc.bufflen == -1
	|| loc.index != grid_info->width * grid_info->height || loc.error || g_bool)
		return (-2);
	return (loc.index_of_max);
}

void	find_square(char *file_title)
{
	t_grid_prop	grid_info;
	int			*main_grid;
	int			index;

	if (!read_first_line(&grid_info, file_title))
		return (ft_puterr("map error\n"));
	if (!count_columns(&grid_info, file_title))
		return (ft_puterr("map error\n"));
	if (!(main_grid = malloc(sizeof(int) *
		(grid_info.width * grid_info.height))))
		return (ft_puterr("malloc error\n"));
	if ((unsigned long)grid_info.height *
		(unsigned long)grid_info.width > 2000000000)
		return (ft_puterr("file too big\n"));
	if ((index = fill_up_grid(main_grid, &grid_info, file_title)) < 0)
	{
		free(main_grid);
		if (index == -2)
			return (ft_puterr("map error\n"));
		else
			return (ft_puterr("malloc error\n"));
	}
	g_bool = 0;
	print_result(main_grid, grid_info, index);
}
