/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 20:28:20 by charles           #+#    #+#             */
/*   Updated: 2020/04/26 14:39:40 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers_test.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::string option(argv[1]);
        if (option == "vector")
            vectorTest();
        if (option == "list")
            listTest();
        if (option == "stack")
            stackTest();
    }
    else
    {
        vectorTest();
        listTest();
        stackTest();
    }
    return 0;
}
