/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 10:23:07 by tpetit            #+#    #+#             */
/*   Updated: 2020/10/01 10:34:13 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_atoi(char *str)
{
    int nb;

    nb = 0;
    while (*str)
    {
        nb = nb * 10 + *str - '0';
        str++;
    }
    return (nb);
}

void print_hexa(int nbr)
{
    const char *hexa = "0123456789abcdef";

    if (nbr)
    {
        print_hexa(nbr / 16);
        ft_putchar(hexa[nbr % 16]);
    }
}

int main(int argc, char **argv)
{
    
    int nbr;

    nbr = 0;
    if (argc != 2)
        ;
    else
    {
        nbr = ft_atoi(argv[1]);
        print_hexa(nbr);
    }
    ft_putchar('\n');
    return (0);
}