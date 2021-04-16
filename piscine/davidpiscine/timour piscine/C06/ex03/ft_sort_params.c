/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:04:04 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:01:20 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	if (s1[i] != '\0')
		return (s1[i]);
	else if (s2[i] != '\0')
		return (0 - s2[i]);
	return (0);
}

void	ft_print_params(char *parname, char **argv)
{
	int i;
	int j;

	i = -1;
	while (argv[++i])
	{
		j = -1;
		if (!ft_strcmp(parname, argv[i]))
		{
			while (parname[++j])
			{
				write(1, &parname[j], 1);
			}
			write(1, "\n", 1);
		}
	}
}

int		main(int argc, char **argv)
{
	int i;
	int j;
	int min;
	int last;

	i = 0;
	last = 0;
	while (++i < argc)
	{
		j = 0;
		min = 0;
		while (++j < argc)
		{
			if (ft_strcmp(argv[j], argv[min]) < 0 || min == 0)
			{
				if ((ft_strcmp(argv[j], argv[last]) > 0) || last == 0)
					min = j;
			}
		}
		min ? ft_print_params(argv[min], argv) : 0;
		last = min ? min : last;
	}
	return (0);
}
