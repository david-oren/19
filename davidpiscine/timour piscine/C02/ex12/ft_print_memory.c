/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:27:46 by tpetit            #+#    #+#             */
/*   Updated: 2020/09/24 18:58:53 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char *g_hexa = "0123456789abcdef";
int g_count = 0;

void	ft_putstr(char *str, int nb)
{
	int i;

	i = -1;
	while (str[++i] && --nb + 1)
		write(1, &str[i], 1);
}

void	addr_size(unsigned long addr)
{
	if (addr)
	{
		addr_size(addr / 16);
		g_count++;
	}
}

void	int_in_hex(unsigned long addr)
{
	if (addr)
	{
		int_in_hex(addr / 16);
		ft_putstr(&g_hexa[addr % 16], 1);
	}
}

void	ft_print_end_line(char *addr, int max, int index)
{
	int i;

	i = -1;
	while (++i < 16 && (max > index + i))
	{
		if ((unsigned char)addr[i] < 16)
			ft_putstr("0", 1);
		if ((unsigned char)addr[i] == 0)
			ft_putstr("0", 1);
		int_in_hex((unsigned char)addr[i]);
		if (i % 2)
			ft_putstr(" ", 1);
	}
	i--;
	while (++i < 16)
	{
		if (i % 2)
			ft_putstr(" ", 1);
		ft_putstr("  ", 2);
	}
	i = -1;
	while (++i < 16 && (max > index + i))
		addr[i] <= 31 ? ft_putstr(".", 1) : ft_putstr(&addr[i], 1);
}

void	ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				j;

	i = 0;
	while (i < size)
	{
		g_count = 0;
		addr_size((unsigned long)(addr + i));
		j = -1;
		while (++j < 17 - g_count)
			ft_putstr("0", 1);
		int_in_hex((unsigned long)(addr + i));
		ft_putstr(": ", 2);
		ft_print_end_line(addr + i, size, i);
		ft_putstr("\n", 1);
		i += 16;
	}
}
