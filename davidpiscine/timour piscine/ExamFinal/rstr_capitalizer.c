/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 10:35:57 by tpetit            #+#    #+#             */
/*   Updated: 2020/10/01 10:44:18 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str)
{
    int i;

    i = -1;
    while (str[++i])
        ;
    return (i);
}

int is_not_word(char c)
{
    if (!c || c == ' ' || c == '\t')
        return (1);
    return (0);
}

void ft_rstrcap(char *str)
{
    int i;

    i = -1;
    while (str[++i])
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    i = -1;
    while (str[++i])
    {
        if (is_not_word(str[i + 1]) && (str[i] >= 'a' && str[i] <= 'z'))
            str[i] -= 32;
    }
    write(1, str, ft_strlen(str));
}

int main(int argc, char **argv)
{
    int i;

    i = 0;
    while (++i < argc)
    {
        ft_rstrcap(argv[i]);
        write(1, "\n", 1);
    }
    if (argc == 1)
        write(1, "\n", 1);
    return (0);
}