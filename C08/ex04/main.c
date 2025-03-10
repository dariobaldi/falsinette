/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:01:06 by dbaldivi          #+#    #+#             */
/*   Updated: 2025/03/10 11:18:50 by dbaldivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

int	main(int argc, char **argv)
{

	struct s_stock_str *list = ft_strs_to_tab(argc, argv);
	
	ft_show_tab(list);
	printf("str= %p copy=%p size=%d\n", list[argc].str, list[argc].copy, list[argc].size);
}
