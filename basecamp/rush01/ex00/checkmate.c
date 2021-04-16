/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:13:21 by cjulienn          #+#    #+#             */
/*   Updated: 2021/02/22 11:34:43 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		ft_checkmate(char *c_i)		
{
	int checkmate;
	int i;
	int bool_i;

	checkmate = 0;
	i = 0;							
	while (i < 4)   si la solution est imposible c est un message d erreur 		comparer le haut et le bas
	{				si row 1 c est 4 alors a l oppose y a un 1
		bool_i = (c_i[i] == '4' && c_i[i + 4] != '1') ? 1 : 0;		
		bool_i = ((c_i[i] == '3' && c_i[i + 4] != '2') || bool_i) ? 1 : 0;		quand y a 3 soit un 2 soit 1 en face
		if ((c_i[i] != '2' && c_i[i + 4] == c_i[i]) || bool_i)		si pas = 2 alors input en face doit different
			checkmate++;
		i++;
	}
	while (i < 8)   comparer le bas avec le haut
	{
		bool_i = (c_i[i] == '4' && c_i[i - 4] != '1') ? 1 : 0;		
		bool_i = ((c_i[i] == '3' && c_i[i - 4] != '2') || bool_i) ? 1 : 0;
		if ((c_i[i] != '2' && c_i[i - 4] == c_i[i]) || bool_i)
			checkmate++;
		i++;
	}
	checkmate = ft_checkmate_2(c_i, checkmate, i);
	return (checkmate);
}

int		ft_checkmate_2(char *cleaned_input, int checkmate, int i)
{
	while (i < 12)  gauche droite
	{
		if (cleaned_input[i] == '4' && cleaned_input[i + 4] != '1')
			checkmate++;
		if (cleaned_input[i] == '3' && cleaned_input[i + 4] != '2')
			checkmate++;
		if (cleaned_input[i] != '2' && cleaned_input[i + 4] == cleaned_input[i])
			checkmate++;
		i++;
	}
	while (i < 16)		droite gauche
	{
		if (cleaned_input[i] == '4' && cleaned_input[i - 4] != '1')
			checkmate++;
		if (cleaned_input[i] == '3' && cleaned_input[i - 4] != '2')
			checkmate++;
		if (cleaned_input[i] != '2' && cleaned_input[i - 4] == cleaned_input[i])
			checkmate++;
		i++;
	}
	return (checkmate);
}
