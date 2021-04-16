/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 09:58:12 by ctirions          #+#    #+#             */
/*   Updated: 2020/09/20 17:56:09 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char		g_tab[4][4] = {"0000", "0000", "0000", "0000"};
int			recurse(int *ptr, char argv[31]);

int			check_error(int argc, char *argv)
{
	int i;

	i = 0;
	if (argc != 2)
		return (1);
	while (argv[i])
		i++;
	if (i != 31)
		return (1);
	return (0);
}

char		*create_input_tab(char argv[31])
{
	int		i;
	char	*input_tab;

	input_tab = malloc(sizeof(*input_tab) * 16);
	i = -1;
	while (++i < 31)
		if (!(i % 2))
			input_tab[i / 2] = argv[i];
	return (input_tab);
}

int			main(int argc, char **argv)
{
	int		victory_condition;
	int		*ptr;

	victory_condition = 0;
	ptr = &victory_condition;
	if (check_error(argc, argv[1]))
		write(1, "Error\n", 6);
	else if (recurse(ptr, argv[1]) == 0)
		write(1, "Error\n", 6);
	return (0);
}
