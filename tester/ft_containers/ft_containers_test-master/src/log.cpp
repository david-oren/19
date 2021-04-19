/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 21:08:51 by charles           #+#    #+#             */
/*   Updated: 2020/04/26 12:09:53 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers_test.hpp"

std::string testName = "";
std::string testContainer = "";

void log(const std::string& prefix,
         const std::string& filename,
         int lineNum,
         const std::string& code)
{
    std::cout << prefix << "{"
              << testContainer << "} {"
              << ::testName << "} "
              << filename << ':'
              << lineNum
              << " (" << code << ")"
              << std::endl;
}
