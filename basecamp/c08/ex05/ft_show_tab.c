/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daoren <daoren@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 21:41:30 by daoren            #+#    #+#             */
/*   Updated: 2021/02/25 10:23:15 by daoren           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int        main(void)
{
    char *av[] = {"hello",
                "ca va",
                "ok"};
    int ac = 3;
    t_stock_str    *stock_str;
    stock_str = ft_strs_to_tab(ac, av);
    printf("%d\n", stock_str[0].size);
    printf("%s\n", stock_str[0].str);
    printf("%s\n", stock_str[0].copy);
    printf("%d\n", stock_str[1].size);
    printf("%s\n", stock_str[1].str);
    printf("%s\n", stock_str[1].copy);
    printf("%d\n", stock_str[2].size);
    printf("%s\n", stock_str[2].str);
    printf("%s\n", stock_str[2].copy);
    return (0);
}
