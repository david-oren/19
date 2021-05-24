/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 20:19:44 by daoren            #+#    #+#             */
/*   Updated: 2021/04/29 17:50:03 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//une variable static c'est une variable qui ne se réinitialise pas quand tu rappelle une fonction.
//buffer: Pour réduire la fragmentation de la mémoire et améliorer les performances d'écriture vers un fichier 
//plutôt que de mettre en attente de nombreux petits événements individuellement vers l'agent de journalisation de fichier, 
//les événements peuvent être mis en mémoire tampon par blocs d'une taille spécifiée avant la mise en attente pour écriture. 
//L'option buffer_size indique la taille maximale que le programme cherche à construire en combinant de plus petits événements en un grand tampon.


#include "get_next_line.h"

char	*ft_check_error(int fd, char **line)
{
	char	*buff;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1 || !line)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	return (buff);
}

int	ft_backslash_checker(char *str) // si il existe encore ou non un \n dans le retour de gnljoin
{
	int	i;

	if (!str)
		return (0);
	i = -1;					// car pre incrementation
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

char	*ft_get_line(char *str)		// elle va permettre de recuperer la ligne qui suit en s arretant soit si on arrive a la fin soit quand on a un \n 
{
	char	*dest;
	size_t	size;

	if (!str)
		return (NULL);
	size = 0;
	while (str[size] && str[size] != '\n')
		size++;
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	size = 0;
	while (str[size] && str[size] != '\n')
	{
		dest[size] = str[size];
		size++;
	}
	dest[size] = 0;
	return (dest);			// dest reste a l emplcaement initial return un pointeur vers le debut de la ligne suivante mais comme on travaille avec les tableau on ne doit pas renvoyer le pointeur sur dest
}

int	ft_return(char **buff, int i, char **line, char **str_save)  //ENCORE A FAIRE........................................................
{
	free(*buff);
	*line = ft_get_line(*str_save);								// 
	if (!line)													// 
		return (-1);
	*str_save = ft_strchr_dup_remix(*str_save, '\n');			//
	if (!*str_save && i != 0)
		return (-1);
	if (i)
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line) // ENCORE A FAIRE........................................................
{
	static char	*str_save;		// quelle ligne on se situe
	char		*buff;			// contient le contenu de read donc une ligne ou null si il y a une erreur
	int			i;

	buff = ft_check_error(fd, line);
	if (!buff)
		return (-1);			// voir pdf
	i = 1;
	while (!ft_backslash_checker(str_save) && i)	// on continue la boucle tant qu il reste une ligne et que on est pas en face d un \n
	{
		i = (int)read(fd, buff, BUFFER_SIZE);			// la fonction read va permettre de lire un fichier et s arrete des qu il y a un retour a la ligne et retourne la ligne ou il se trouve
		if (i < 0)
		{
			free(buff);
			return (-1);
		}
		buff[i] = 0;
		str_save = ft_gnljoin(str_save, buff);
		if (!str_save)
			return (-1);
	}
	return (ft_return(&buff, i, line, &str_save));
}
