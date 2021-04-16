/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:37:18 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/25 09:11:18 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mylib.h"

int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc == 1)
    {
        ft_rewrite_userinput();
        return (0);
    }
    while (++i < argc)
    {
        if (!ft_strcmp(argv[i], "-"))
        {
            ft_rewrite_userinput();
            return (0);
        }
        if (ft_open_file(argv[i]) == -1)
            ft_puterr(argv[0], argv[i], strerror(errno));     
    }
    return (0);
}