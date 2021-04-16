/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 21:50:57 by daoren            #+#    #+#             */
/*   Updated: 2021/02/24 21:27:10 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdlib.h>

int		ft_strlen(char *str)
{
	int a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

int ft_strlentotal(int size, char **strs, char *sep) // calculer la longueur total des caractere + les separateurs
{
	int len;
	int i;

	i = 0;
	len = 0;
	while (i < size)
	{
		len = ft_strlen(strs[i]) + len;
		i++;
	}
	return (len + (ft_strlen(sep) * (size - 1)));
}

char	*ft_strcat(char *dest, char *src) // appent source dans dest
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char *ft_strjoin(int size, char **strs, char *sep) // strcat mais dynamique avec le fait de mettre des separateurs
{
	int i;
	int count;
	char *dest;
	
	count = 0;
	if (size < 1) //si la taille de ma string est inferieur ou egale a zero pour eviter le sigabort
		return (dest = malloc(0)); 
	dest = malloc(ft_strlentotal(size, strs, sep)); //creeer assez d espace pour la longueur total des caractere + les separateurs
	if (!(dest)) //proteger ma malloc
		return (0);
	i = 0;
	while (i < size) //pouvoir append mes string dans dest
	{
		ft_strcat(dest , strs[i]); // append les caractere
		if ((i + 1) < size)
			ft_strcat(dest, sep); // append les separateur
		i++;
	}
	return(dest);
}*/

#include <stdlib.h>

int			ft_strlen(char *str)
{
	int a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

int			ft_strlentotal(int size, char **strs, char *sep)
{
	int len;
	int i;

	i = 0;
	len = 0;
	while (i < size)
	{
		len = ft_strlen(strs[i]) + len;
		i++;
	}
	return (len + (ft_strlen(sep) * (size - 1)));
}

char		*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char		*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		count;
	char	*dest;

	count = 0;
	if (size < 1)
	{
		dest = malloc(1);
		dest[0] = '\0';
		return (dest);
	}
	dest = malloc(ft_strlentotal(size, strs, sep) + 1);
	if (!(dest))
		return (0);
	i = 0;
	while (i < size)
	{
		ft_strcat(dest, strs[i]);
		if ((i + 1) < size)
			ft_strcat(dest, sep);
		i++;
	}
	return (dest);
}


//ex03
#include <stdio.h>
int main() {
    char *test[] = {
    "salut",
    "mon",
    "pote",
    "à",
    "la",
    "compote",
    "de",
    "pomme"
    };
    char sep[] = " - ";
    printf("is       -->%s\n", ft_strjoin(8, test, sep));
    printf("sould be -->salut - mon - pote - à - la - compote - de - pomme\n\n");
    char *test2[] = {};
    printf("is       -->%s\n", ft_strjoin(-3, test, sep));
    printf("sould be -->");
    return (0);
}
