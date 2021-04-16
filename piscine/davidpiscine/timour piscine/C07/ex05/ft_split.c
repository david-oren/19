/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 19:23:02 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 19:01:42 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		is_in_list(char *list, char c)
{
	int i;

	i = -1;
	while (list[++i])
	{
		if (list[i] == c)
			return (1);
	}
	return (0);
}

int		count_words(char *str, char *charset)
{
	int i;
	int inword;
	int count;

	i = -1;
	inword = 0;
	count = 0;
	while (str[++i])
	{
		if (is_in_list(charset, str[i]))
		{
			if (inword)
			{
				inword = 0;
				count++;
			}
		}
		else if (!inword)
			inword = 1;
	}
	if (i > 0 && !is_in_list(charset, str[i - 1]))
		count++;
	return (count);
}

void	add_word(int *ijcw, char *str, char **dest)
{
	char *currdst;

	ijcw[1] = -1;
	if (str[ijcw[0] + 1] == 0)
	{
		ijcw[2]++;
		ijcw[0]++;
	}
	currdst = malloc(sizeof(char) * (ijcw[2] + 1));
	while (++ijcw[1] < ijcw[2])
	{
		currdst[ijcw[1]] = str[ijcw[0] - ijcw[2] + ijcw[1]];
	}
	currdst[ijcw[1]] = 0;
	dest[ijcw[3]] = currdst;
	ijcw[3]++;
	ijcw[2] = 0;
}

void	ret_world(char **dest, char *str, char *charset)
{
	int		ijcw[4];

	ijcw[0] = -1;
	ijcw[3] = 0;
	ijcw[2] = 0;
	while (str[++ijcw[0]])
	{
		if (!is_in_list(charset, str[ijcw[0]]))
			ijcw[2]++;
		else if (ijcw[2])
		{
			add_word(ijcw, str, dest);
		}
	}
	if (ijcw[2])
		add_word(ijcw, str, dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**dest;
	int		count;

	count = count_words(str, charset);
	if (!(dest = malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	if (count)
		ret_world(dest, str, charset);
	dest[count] = 0;
	return (dest);
}
