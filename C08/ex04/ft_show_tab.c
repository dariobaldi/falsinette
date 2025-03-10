/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:38:50 by dbaldivi          #+#    #+#             */
/*   Updated: 2025/03/10 17:14:33 by dbaldivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_print_string(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	ft_putnbr(int nbr)
{
	int		divider;
	char	*decimal;

	decimal = "0123456789";
	divider = 1;
	if (nbr < 0)
	{
		write(1, "-", 1);
		divider = -1 - 9 * (nbr < -9);
	}
	while (nbr / divider >= 10)
		divider *= 10;
	while (divider)
	{
		write(1, decimal + nbr / divider, 1);
		nbr %= divider;
		divider /= 10;
	}
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != NULL)
	{
		ft_print_string((par + i)->str);
		ft_putnbr((par + i)->size);
		ft_print_string((par + i)->copy);
		i++;
	}
}
